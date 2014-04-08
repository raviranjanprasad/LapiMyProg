#!/usr/bin/perl 
#===============================================================================
#
#         FILE: ReadDevice.pl
#
#        USAGE: ./ReadDevice.pl  
#
#  DESCRIPTION: 
#
#      OPTIONS: ---
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Ravi Prasad (), ravi_prasad@symantec.com
# ORGANIZATION: Symantec
#      VERSION: 1.0
#      CREATED: 08/14/2013 06:59:07 PM
#     REVISION: ---
#===============================================================================

use strict;
use warnings;
use utf8;

my (@sympdList);
my (%sidHdiskMap);
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
  foreach $element(@sympdList){
	     print("$element\n");
   }
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
  my ($sid,$element);
  foreach $element(@sympdList){
    @arr=split(/\s+/,$element); 
    $arr[0] =~ s/rhdisk/hdisk/g;
    $sidHdiskMap{$arr[1]}=$arr[0];
  }	

  foreach $sid (keys(%sidHdiskMap)) {
    print("$sid => $sidHdiskMap{$sid}\n");
  }
} ## --- end sub MapDevice



#===  FUNCTION  ================================================================
#         NAME: ReadNbfirescan
#      PURPOSE: 
#   PARAMETERS: ????
#      RETURNS: ????
#  DESCRIPTION: ????
#       THROWS: no exceptions
#     COMMENTS: none
#     SEE ALSO: n/a
#===============================================================================
sub ReadNbfirescan {
  my(@temp);
  my($filePath,$element,$arrSz);
  chomp($filePath = $_[0]);
  unless (-e $filePath){
     die("$filePath Doesn't Exists\n");
  }
  open INPUT_FILE, "$filePath"  || die "Can't open $filePath: $!\n";
  while (<INPUT_FILE>) {
        next if ($_ =~ /^$/) || ($_ !~ /\/dev\/hdisk/);
        chomp($_);
     push(@temp, $_);
  }
  close (INPUT_FILE);
  foreach $element(@temp){
         print("$element\n");
   }
  $arrSz = @temp; 
  print("Length of the Array ::$arrSz\n"); 
	return $arrSz;
} ## --- end sub ReadNbfirescan


#-------------------------------------------------------------------------------
#                       Main Program
#-------------------------------------------------------------------------------
my ($file,$nbfile,$count);
$file = "device";
$nbfile = "nbfirescan.txt";
ReadFile($file);
MapDevice();
$count=ReadNbfirescan($nbfile);
print("Count = $count\n");

