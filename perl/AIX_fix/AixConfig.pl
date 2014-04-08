#!/usr/bin/perl
#===============================================================================
#
#         FILE: AixConfig.pl
#
#        USAGE: ./AixConfig.pl
#
#  DESCRIPTION: This Script detect and fix the AIX ODM Meta Data corruption.
#               Algoritham to Detect and FIX the ODM Meta Data corruption.
#               1. Read the Device mapping file.
#               2. Run sympd list command
#               3. Get the hdisk list corresponding to Devices in device mapping file.
#               4. check the availabiltiy of the target devices on the host with nbfirescan.
#               5. If devices are not persent.
#                       a. Rescan the devices with "cfgmgr -v"
#                       b. Recheck the availability of devices on the host with nbfirescan.
#                       If Devices are still not Available.
#                               a. Bring the devices in RW state by Spliting them [symmir]
#                               b. Clear the VG of the devices.
#                               c. Cleart the PVID of the devices.
#               6. Format the devices with dd command.
#               7. Give the Successful completion of FIX, and advice to sync the source and
#                  target devices to perform any further snapshot operation.
#
#      OPTIONS: ---
# REQUIREMENTS: Detection and Resolution for AIX ODM Meta Data corruption.
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Ravi Prasad (), ravi_prasad@symantec.com
# ORGANIZATION: Symantec
#      VERSION: 1.0
#      CREATED: 08/17/2013 01:48:23 PM
#     REVISION: ---
#===============================================================================

use strict;
use warnings;
use utf8;

my ($user,$count,$filePath,$i,$j);
my (@devArray);
my (@sourceDevice, @targetDevice,@osDev,@corruptDev,@syncDev);
my (@sympdList,@mapFilePath,@formatDev);
my (%sidHdiskMap);


#===  FUNCTION  ================================================================
#         NAME: ReadTempSourceTargetMappedFile
#      PURPOSE:
#   PARAMETERS: NA
#      RETURNS: NA
#  DESCRIPTION: #Take the temporary source target mapping file as imput from user.
#                               Temporary file that contains only the source and target device IDs
#                               separated by a space. (Only one source-target pair can exist in a temporary
#                               file
#                               For example, if the source (STD) device ID is 0050 and the target (BCV) device
#                               ID is 0060, the temporary file should contain the following:
#                               0050 0060
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub ReadTempSourceTargetMappedFile {
        print "\nEnter the no of Temprory Source target mapped file:";
        chomp($count = <>);

        for ($i = 1; $i <= $count; $i++) {
             print ("Enter $i File Full Path\n");
             chomp($filePath = <>);
             unless (-e $filePath){
                        die("$filePath Doesn't Exists\n");
             }
             push(@mapFilePath, $filePath);
             open INPUT_FILE, "$filePath"  || die "Can't open $filePath: $!\n";
             while (<INPUT_FILE>) {
            next if ($_ =~ /^$/);
                push(@devArray, $_);
             }
             close (INPUT_FILE);
        }
        #print @devArray;

} ## --- end sub ReadTempSourceTargetMappedFile

#===  FUNCTION  ==============================================================
#         NAME: GetSourceAndTagetDevice
#      PURPOSE: To parse the source target mapping file e.g mirror1,mirror2
#   PARAMETERS: file hadles
#      RETURNS: NA
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub GetSourceAndTagetDevice {
    my (@temp) = @_;
    my (@array);

    for($i=0;$i < @temp; $i++){
      chomp($temp[$i]);
      @array = split(/\s+/, $temp[$i]);
      if(!grep(/$array[0]/, @sourceDevice)){
        push(@sourceDevice, $array[0]);
      }
      if(!grep(/$array[1]/, @targetDevice)){
        push(@targetDevice, $array[1]);
      }

  }
    print "\nSource Array elements\n";
    print join("\n",@sourceDevice);
    print "\nTarget Array elements\n";
    print join("\n",@targetDevice);
    print "\n";
} ## --- end sub GetSourceAndTagetDevice


#===  FUNCTION  ================================================================
#         NAME: FormSympdListCommand
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub FormSympdListCommand {
    my ($command,$symcliPath,$args,$ele);
        my (@arr1, @arr2);

        $command ="";
        $symcliPath="/opt/emc/SYMCLI/V7.1.0/bin/sympd";
        print"-----------------------------------------------------------------\n";
        print "Enter the sympd path<Example: /opt/emc/SYMCLI/V7.1.0/bin/sympd>";
        chomp($symcliPath = <>);
        unless (-e $symcliPath){
          die("$symcliPath doesn't Exists\n");
        }

        $command = $command .$symcliPath;

        $args = "";
        $command = $command . " list" . "|" . "egrep ";
        $args = $args . "\'";
        foreach $ele (@targetDevice){
        $args = $args.$ele."|";
        }
        $args=~ s/\|$//g;
        $args = $args . "\'";
        $command = $command . $args;

        return $command;
} ## --- end sub FormSympdListCommand


#===  FUNCTION  ================================================================
#         NAME: FormNbfirescanCommand
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub FormNbfirescanCommand {
        my ($command,$nbfirescan,$args,$ele);
        my (@arr1, @arr2);

        $command ="";
        $nbfirescan="/usr/openv/netbackup/bin/nbfirescan";
        $command = $command .$nbfirescan;

        $args = "";
        $command = $command ."|"."egrep ";
        $args = $args . "\'";
        foreach $ele (@osDev){
        $args = $args.$ele."|";
        }
        $args=~ s/\|$//g;
        $args = $args . "\'";
        $command = $command . $args;

        return $command;

} ## --- end sub FormNbfirescanCommand

#===  FUNCTION  ================================================================
#         NAME: ReadFile
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub ReadFile {
  my ($filePath,$element);
  chomp($filePath = $_[0]);
  unless (-e $filePath){
     die("$filePath Doesn't Exists\n");
  }
  open INPUT_FILE, "$filePath"  || die "Can't open $filePath: $!\n";
  while (<INPUT_FILE>) {
        next if ($_ =~ /^$/);
        chomp($_);
     push(@sympdList, $_);
  }
  close (INPUT_FILE);
  #foreach $element(@sympdList){
  #       print("$element\n");
  # }
} ## --- end sub ReadFile


#===  FUNCTION  ================================================================
#         NAME: MapDevice
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub MapDevice {
  my (@arr);
  my ($sid,$element,$temp);
  foreach $element(@sympdList){
    @arr=split(/\s+/,$element);
    $arr[0] =~ s/rhdisk/hdisk/g;
    push(@formatDev,$arr[0]);
    $temp=$arr[0]."  ".$arr[8];
    $sidHdiskMap{$arr[1]}=$temp;
    $arr[0] =~ s/\/dev\///g;
    push(@osDev,$arr[0]);
    if($arr[8] =~ /NR/){
      push(@syncDev,$arr[0]);
    }
  }

  foreach $sid (keys(%sidHdiskMap)) {
    print("$sid => $sidHdiskMap{$sid}\n");
  }

} ## --- end sub MapDevice


#===  FUNCTION  ================================================================
#         NAME: DetectMetaDataCorruptDevices
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub DetectMetaDataCorruptDevices {
  my ($filePath,$element,$sid,$arrSz);
  my (@arrDev);
  chomp($filePath = $_[0]);
  unless (-e $filePath){
     die("$filePath Doesn't Exists\n");
  }
  $arrSz = @corruptDev;
  delete @corruptDev[0..$arrSz];

  open INPUT_FILE, "$filePath"  || die "Can't open $filePath: $!\n";
  while (<INPUT_FILE>) {
        next if ($_ =~ /^$/);
        chomp($_);
        @arrDev = split(/\s+/,$_);
        if(($arrDev[1] =~ /-/) || ($arrDev[2] =~ /-/)){
          $arrDev[0] =~ s/\/dev\///g;
          push(@corruptDev, $arrDev[0]);
        }
  }
  #foreach $element(@corruptDev){
  #  print("\n$corruptDev[$element]\n");
  #}
  $arrSz = @corruptDev;
  if($arrSz > 0){
     print("\n--------------------------------------------------------------------\n");
     print("ODM Meta Data corruption found for following $arrSz devices........\n");
     foreach $element(@corruptDev){
       foreach $sid (keys(%sidHdiskMap)){
          if ($sidHdiskMap{$sid} =~ /$element/){
             print("$sid ---> $element\n");
          }
       }
     }
    print("\n--------------------------------------------------------------------\n");
    return($arrSz);
 }
} ## --- end sub DetectMetaDataCorruptDevices


#===  FUNCTION  ================================================================
#         NAME: GetOSDeviceForSoureceAndTarget
#      PURPOSE: Get the corresponding "/dev/hdisk" device list of the source LUN
#               and target LUNs masked on the host
#               e.g /dev/hdisk26          2069
#                                       /dev/hdisk38          206A
#                                       /dev/hdisk39          206B
#                                       /dev/hdisk40          206C
#                                       /dev/hdisk41          206D
#                                       /dev/hdisk42          206E
#                                       /dev/hdisk43          206F
#                                       /dev/hdisk44          2070
#                                       /dev/hdisk50          2071
#
#   PARAMETERS: NA
#      RETURNS: NA
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub GetOSDeviceForSoureceAndTarget {
    my ($sympdListCommand,$nbfirescanCmd,$user,$output,$nbfirescanOut);
    my ($rescanCmd,$cfgmgrOut);
    $sympdListCommand = FormSympdListCommand();

    print "sympd list command:: \n";
    print "$sympdListCommand\n";
    print("\n------------------------------------------------------------------\n");
    print"\n Will you like to run sympd list command[y|n]:";
    chomp($user = <>);
    if ($user !~ /y|Y/){
        die("Bye..............\n");
    }
    $output ="sympdList.txt";
    print("\n Please wait........... Luns are getting mapped with OS hdisk\n");
    system "$sympdListCommand > $output";
        if ( $? == -1 ) {
           print "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                printf "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;

        }
    print("\n------------------------------------------------------------------\n");
    ReadFile($output);
    MapDevice();
    print("\n------------------------------------------------------------------\n");
    print"\n Is the Device Mapping for target Device Correct[y|n]:";
    chomp($user = <>);
    if ($user !~ /y|Y/){
        die("Wrong Device Mapping Bye..............\n");
    }


    print("\n------------------------------------------------------------------\n");
    print("Running nbfriescan comamnd on the target Deivces\n");
    print("\n------------------------------------------------------------------\n");
    $nbfirescanCmd=FormNbfirescanCommand();
    $nbfirescanOut="nbfirescan.txt";
    print("\n Please wait........... Scanning the target devices\n");
    system "$nbfirescanCmd > $nbfirescanOut";
        if ( $? == -1 ) {
           print "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                printf "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;

        }
    $count = DetectMetaDataCorruptDevices($nbfirescanOut);
    if(!$count){
      print "\n------------------------------------------\n";
      print "           Testing Complete                 \n";
      print "\n------------------------------------------\n";
      die "No ODM Meta Data corruption Found on this Host\n";
    }
    print("\n------------------------------------------------------------------\n");
    print("Running explict rescan command with cfgmgr -v\n");
    print("Please wait ..............rescan of device may take few seconds\n");
    $rescanCmd = "/usr/sbin/cfgmgr -v";
    $cfgmgrOut = "cfgmgrOut.txt";
    system "$rescanCmd > $cfgmgrOut";
        if ( $? == -1 ) {
           print "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                printf "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;

        }
    print("\n Rescan of devices completed ..........\n");
    print("\n------------------------------------------------------------------\n");
    print("\n Reverifying the ODM corruption after the Recan of devices\n");
    print("\n------------------------------------------------------------------\n");
    $count = DetectMetaDataCorruptDevices($nbfirescanOut);
    if(!$count){
      print "\n------------------------------------------\n";
      print "           Testing Complete                 \n";
      print "\n------------------------------------------\n";
      die "After Rescan No ODM Meta Data corruption Found on this Host\n";
    }
    print("\n------------------------------------------------------------------\n");

} ## --- end sub GetOSDeviceForSoureceAndTarget


#===  FUNCTION  ================================================================
#         NAME: splitNotReadyDevices
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub splitNotReadyDevices {
    my ($sid,$symmir,$filePath,$user,$splitOut,$cmd);
    $symmir="";
    $cmd="/opt/emc/SYMCLI/V7.1.0/bin/symmir";
    print("\n-----------------------------------------------------------------------------\n");
    print("Enter symmir path <Example : /opt/emc/SYMCLI/V7.1.0/bin/symmir>::");
    chomp($user = <>);
    if ($user !~ /symmir/){
       die("Bye..............You can run the above Steps manually\n");
    }
    print("\nEnter the SID of the device::");
    chomp($sid = <>);
    if ($sid =~ //){
        print("\nWrong SID........try Again\n");
        print("\nEnter the SID of the device::");
        chomp($sid = <>);
        if ($sid =~ //){
           die("\n Wrond SID.........Bye");
        }
    }
    $cmd=$user;
    foreach $filePath (@mapFilePath){
        $symmir=$cmd."  -sid"." "."$sid"." "."split"." "."-f"." "."$filePath";
        print("\n-----------------------------------------------------------------------------\n");
        print("\n Command to split the device::$symmir\n");
        print("NOTE: If the device is in NR state and not in RW state then only Run this command\n");
        print("\n-----------------------------------------------------------------------------\n");
        print("\n Do you want to run the above Split command[y/n]::");
        chomp($user = <>);
        if ($user !~ /y|Y/){
           die("Bye..............You can run the above Steps manually\n");
        }
        $splitOut="splitOut.txt";
        print "in device file '$filePath' (y/[n]) ?";
        system "$symmir >> $splitOut";
        if ( $? == -1 ) {
           print "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                printf "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;

        }
            print("\n-----------------------------------------------------------------------------\n");
    }

}


#===  FUNCTION  ================================================================
#         NAME: clearPVID
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub clearPVID {
    my ($lspvCmd,$lspvOut,$element);
    my ($user,$disk,$path,$cmd,$PVIDout);
    my ($vg,$res1,$res2);
    my (@lsdevArray,@vgArray,@temp,@temp1);
    my (%VGDevice,%seen);

    $path="/usr/sbin/chdev";
    $PVIDout="PVIDout.txt";
    $lspvCmd="/usr/sbin/lspv";
    $lspvOut="lspvOut.txt";
    system "$lspvCmd > $lspvOut";
        if ( $? == -1 ) {
           print "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                printf "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;
    }

    print("\n------------------------------------------------------------------\n");
    print("\n It Require to Clear the VG associated with the Target Devices.\n");
    print("\n------------------------------------------------------------------\n");
    print("\nFollowing VG are associated with the target Devices\n");

    open INPUT_FILE, "$lspvOut"  || die "Can't open $filePath: $!\n";
    while (<INPUT_FILE>) {
       next if ($_ =~ /^$/);
       chomp($_);
       push(@lsdevArray, $_);
    }

    close (INPUT_FILE);
    foreach $element(@lsdevArray){
       @temp=split(/\s+/,$element);
       if($temp[2] =~ /^vg[0-9]+/){
         $VGDevice{$temp[0]}=$temp[2];
         push(@temp1,$temp[2]);
       }
    }

    foreach $disk (keys(%VGDevice)) {
        print("$disk => $VGDevice{$disk}\n");
    }

    foreach (@temp1) {
      push(@vgArray, $_) unless ($seen{$_}++);
    }

    print("\n------------------------------------------------------------------\n");

    foreach $vg (@vgArray){
        print("\n Do you want to delete the VG $vg [y|n]::");
        chomp($user = <>);
        if ($user !~ /y|Y/){
                 die("Bye..............You can run the this comamnd  manually\n");
        }
        $res1=`/usr/sbin/varyoffvg $vg`;
        $res2=`/usr/sbin/exportvg $vg`;

    }

    print("\n------------------------------------------------------------------\n");
    print("\n Clear the PVID of target devices\n");
    print("\n------------------------------------------------------------------\n");
    foreach $disk(@osDev){
      $cmd=$path." "."-l$disk"." "."-a"." "."pv=clear";
      print "\n $cmd\n";
      print("\n Do you want to clear the PVID of $disk [y/n]::");
      chomp($user = <>);
        if ($user !~ /y|Y/){
           die("Bye..............You can run the this comamnd  manually\n");
        }
      system "$cmd >> $PVIDout";
       if ( $? == -1 ) {
           die "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                die "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;

        }
     $cmd=$path;
    }
    print("\n------------------------------------------------------------------\n");
    print("\n Target Device PVID got cleared successfully.\n");
    print("\n------------------------------------------------------------------\n");

} ## --- end sub clearPVID


#===  FUNCTION  ================================================================
#         NAME: formatTargetDevice
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub formatTargetDevice {
    my ($cmd,$element,$formatOut);
    my ($ddcmd,$input,$res);
    print("\n------------------------------------------------------------------\n");
    print("\nNext Step will format the target Devices\n");
    print("\n------------------------------------------------------------------\n");
    print("\nPlease Re-Confirm if you real want to proceed, It will format the target devices[y|n]::");
    chomp($user = <>);
    if ($user !~ /y|Y/){
        die("Bye..............You can Format the devices manually with dd command\n");
    }
    $cmd="";
    $ddcmd="/usr/bin/dd";
    $input="/dev/zero";
    $formatOut="ddCmdOut.txt";

    foreach $element(@formatDev){
      print("\n------------------------------------------------------------------\n");
      print("WARNING......WARNING..........WARNING\n");
      print("About to format $element\n");
      print("\n------------------------------------------------------------------\n");
      $cmd=$ddcmd. " ". "if=$input". " ". "of=$element". " ". "bs=1024k". " ". "count=500";
      print "$cmd\n";
      print("Do you want to format $element [y/n]::");
      chomp($user = <>);
      next if ($user !~ /y|Y/);
      system "$cmd >> $formatOut";
        if ( $? == -1 ) {
           die "Command failed to execute: $!\n";
        }
        elsif ( $? & 127 ) {
                die "The Command died with signal %d, %s a coredump\n",
                ( $? & 127 ), ( $? & 128 ) ? 'with' : 'without';
        }
        else {
                printf "Command exited with value %d\n", $? >> 8;

        }
    }
      print("\n------------------------------------------------------------------\n");
      print "Please wait ..............Rescaning the Host with cfgmgr -v command\n";
      print("\n------------------------------------------------------------------\n");
      $res = `/usr/sbin/cfgmgr -v`;

} ## --- end sub formatTargetDevice


#===  FUNCTION  ================================================================
#         NAME: fixODMmetaDataCorruption
#      PURPOSE:
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub fixODMmetaDataCorruption{
    my ($user);
    print("\n------------------------------------------------------------------\n");
    print("          Procedure to FIX the ODM corruption\n");
    print("1. Split the NR (Not ready Devices\n");
    print("2. Run cfgmgr -v command to rescan the device\n");
    print("3. Clare the pvid of the target Devices\n");
    print("4. Reverify the Devices availability By running nbfirescan\n");
    print("5. Format the Devices with dd command\n");
    print("\n------------------------------------------------------------------\n");
    print("Do you want to Proceed above metioned Steps[Y|n]::");
    chomp($user = <>);
    if ($user !~ /y|Y/){
        die("Bye..............You can run the above Steps manually\n");
    }
} ## --- end sub splitNotReadyDevices


#-------------------------------------------------------------------------------
#                      MAIN PROGRAM STARTS
#-------------------------------------------------------------------------------

print "----------------------------------------------------------------------------------------\n";
print "                                       Welcome                               \n";
print "This script is for Detection and Resolution to fix the ODM corruption on the AIX host.\n";
print "-----------------------------------------------------------------------------------------\n\n";
print "You need to be root user to run this script.                   \n";
print "----------------------------------------------------------------------------------------\n";
print "Ary you a root user [y/n]:";


chomp($user = <>);
if ($user !~ /y|Y/){
   die("please run the script with root user\n");
}


#-------------------------------------------------------------------------------
ReadTempSourceTargetMappedFile();
GetSourceAndTagetDevice(@devArray);

print "--------------------------------------------------------------\n";
print "Confirm the Source and Target device list Shown Above[y/n]:";

chomp($user = <>);
if ($user !~ /y|Y/){
   die("Please verify the Source and Target device with the Temp files\n");
}
print "--------------------------------------------------------------\n";
GetOSDeviceForSoureceAndTarget();
fixODMmetaDataCorruption();
splitNotReadyDevices();
clearPVID();
formatTargetDevice();
print "\n========================================================================================================\n";
print "\n                                  Successfully Fix the ODM corruption \n";
print "\n It require to bring Source and Target  devices in synchoronize state to perform any snapshot operation\n";
print "\n                                  !!............THANKS...............!!\n";
print "\n=========================================================================================================\n";

