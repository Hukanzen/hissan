open(IN,"result.txt");
open(OUT,">rnow.txt");

#$line="11:9292";
while($line=<IN>){
#while($line){
	$line=~s/:(\t|\s)\d+$//;
	print OUT $line;
}

close(IN);
close(OUT);

print "$0 Complete!!!\n";
