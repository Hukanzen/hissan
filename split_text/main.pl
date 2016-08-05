use POSIX 'strftime';

my $i=0;

my $now = strftime "%Y%m%d_%H%M%S", localtime;
my $file="_".$now."_".$i."result.txt";

open(IN,"result.txt");
open(OUT,">".$file);

while($line=<IN>){
	my $fsize=-s $file;
	if($fsize < 99*10**6){
		print OUT $line;
	}else{
		close(OUT);

		$i++;
	#	$now = strftime "%Y%m%d_%H%M%S", localtime;
		$file="_".$now."_".$i."result.txt";
		open(OUT,">".$file);

		print OUT $line;
	}
}

close(IN);
close(OUT);
