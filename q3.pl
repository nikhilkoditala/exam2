my $C_ALPHABETS_RANGE = 20;
my $C_AGE_RANGE = 110;
my $C_ITERATIONS = 5000;

my $name;
my $age;

sub getRandInt {
	return int rand($_[0]);
}

sub getRandChar {
	return chr(65 + getRandInt($C_ALPHABETS_RANGE))
}

my %hashMap;

my $hashStart = time;
for ($a = 0; $a < $C_ITERATIONS; $a++) {
	$name = '';
	for (1..3){
        $name .= getRandChar();
	}
	$age = getRandInt($C_AGE_RANGE);
	$myhash{$name} = $age;
}

my $hashTime = time - $hashStart;

print "Time taken for hash script - $hashTime\n";

my @arr;
my $arrayStart = time;
my $arraySize = 0;
my $duplicate = 0;

for ($a = 0; $a < $C_ITERATIONS; $a++) {
	$duplicate = 0;
	$name = '';
	for (1..3){
        $name .= getRandChar();
	}
	$age = getRandInt($C_AGE_RANGE);
	
	for($b = 0; $b < $arraySize; $b++) {
		if (($arr[$b][0] eq $name) == 1) {
			$duplicate = 1;
			break;
		}
	}
	if ($duplicate == 0) {
		$arr[$i][0] = $name;
		$arr[$i][1] = $age;
		$arraySize++;
	}
}

my $arrayTime = time - $arrayStart;

print "Time taken for array script - $arrayTime\n"