#!/usr/bin/env perl

use Modern::Perl '2013';
use autodie;
use Env qw{ HOME };

if ($#ARGV + 1 < 1 ) {
  print " USAGE:\n";
  print "   $0 <exe name>\n";
  exit 1;
}

my $numtrials = 20;
my $arch = `uname`;
chomp($arch);

my $ex = $ARGV[0];
my $lf = $ex . "_log.txt";
open (NEW,">$lf") or die "ERROR: Can't open $lf\n";
print NEW "Architecture is $arch\n";
if ($arch eq "Darwin") {
  print NEW `system_profiler SPHardwareDataType Hardware`;
}

my $es = "setup_euler.sh";
my $sp = "$HOME/Projects/Euler/Code/";
my $dn = "/dev/null";
for (1..$numtrials) {
  system("pushd $sp >& $dn;. $es; popd >& $dn; (time bin/$ex >> $lf) 2>> $lf");
}

close (NEW);

open INPUT, $lf or die "ERROR: Can't open $lf\n";
my @realtimes;
my @usertimes;
my @systimes;

while(<INPUT>) {
  chomp;
  if (/^real/) {
    my $realtime = timeinsec($_);
    push @realtimes, $realtime;
  }
  if (/^user/) {
    my $usertime = timeinsec($_);
    push @usertimes, $usertime;
  }
  if (/^sys/) {
    my $systime = timeinsec($_);
    push @systimes, $systime;
  }
}

my $lftime = $ex . "_times.txt";
open (OUTPUT,">$lftime") or die "ERROR: Can't open $lftime\n";

printf OUTPUT "\#%11s\t%12s\t%12s\n", "real", "user", "sys";
for (my $i = 0; $i < scalar @realtimes; $i++) {
  printf OUTPUT "%12.3f\t%12.3f\t%12.3f\n", 
  $realtimes[$i], $usertimes[$i], $systimes[$i];
}

close(INPUT);
close(OUTPUT);

my $logdir = $sp . "CPP/reports/";
system("mv $lf $logdir");
system("mv $lftime $logdir");

sub timeinsec {
  my @vals = split(/\s+/,$_[0]);
  my $time = $vals[-1];
  @vals = split(/[a-z]/,$time);
  my $timesize = scalar(@vals)."\n";
  if ($timesize == 2) {
    $time = 60*$vals[0] + $vals[1];
  }
  elsif ($timesize == 3) {
    $time = 60*60*$vals[0] + 60*$vals[1] + $vals[2];
  }
}
