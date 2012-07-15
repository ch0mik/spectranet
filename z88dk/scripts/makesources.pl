#!/usr/bin/perl
use strict;

opendir(DHND, ".") or die("Could not opendir: $!");

while(my $dirent=readdir(DHND))
{
	if($dirent =~ /\.asm/)
	{
		processfile($dirent);
	}
}

sub processfile
{
	my $dirent=shift;
	my $nopaged=$dirent;
	my $paged=$dirent;
	$nopaged=~s/\.asm/_np\.asm/g;
	$paged=~s/\.asm/_p\.asm/g;

	open FHND, "< $dirent" or die("Could not open $dirent: $!");
	my $line=<FHND>;
	if($line =~ /^; process/i)
	{
		open PHND, "> $paged" 
			or die("Could not open $paged: $!");
		open NHND, "> $nopaged"
			or die("Could not open $nopaged: $!");

		my $msg="; do not edit this file, it has been automatically generated.\n";
		print PHND $msg;
		print NHND $msg;

		while(my $line=<FHND>)
		{
			if($line =~ /HLCALL/ || $line =~ /IXCALL/)
			{
				$line=~s/^\s|\s$|\r|\n//g;
				my ($op, $param)=split(/\s{1,}/, $line);
				print PHND "	ld " . substr($op, 0, 2) .", $param\n";
				print PHND "	call $op\n";
				print NHND "	call $param\n";
			}
			else
			{
				print PHND $line;
				print NHND $line;
			}
		}
		close(PHND);
		close(NHND);
	}
	close(FHND);
}

closedir(DHND);
