#!/usr/bin/perl 
#===============================================================================
#
#         FILE: testClearArray.pl
#
#        USAGE: ./testClearArray.pl  
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
#      CREATED: 08/17/2013 09:16:12 PM
#     REVISION: ---
#===============================================================================

my @array = (0,1,2,3,4,5,6);
$size = @array;
print "Size=$size\n";
delete @array[0..$size];
#foreach(@array){$_ = ();}
$size = @array;
print "Now Size=$size\n";

