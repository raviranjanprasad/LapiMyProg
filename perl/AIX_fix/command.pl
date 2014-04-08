#!/usr/bin/perl 
#===============================================================================
#
#         FILE: command.pl
#
#        USAGE: ./command.pl  
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
#      CREATED: 08/12/2013 08:08:38 PM
#     REVISION: ---
#===============================================================================

use strict;
use warnings;
use utf8;

my ($command,$symcliPath,$args,$ele);
my (@arr1, @arr2);

$command ="";

print "Enter the SYMCLI path";
chomp($symcliPath = <>);
$command = $command ."$symcliPath";
@arr1=("22F0","22F1","22F2");
@arr2=("206A","206B","2069","206D","206E","206C","2071","206F","2070");

$args = "";
$command = $command . "sympd list" . "|" . "egrep ";  
$args = $args . "\'";
foreach $ele (@arr1){
  $args = $args .$ele."|";
}
foreach $ele (@arr2){
  $args = $args . $ele."|";
}
$args=~ s/\|$//g;
$args = $args . "\'";



$command = $command . $args;
print "Command formed: \n";
print "$command\n";
