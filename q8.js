function main() {
	var a = 'a - Inide main()';
	console.log('**********main()****************');
	console.log(a);
	function nest1() {
		var b = 'b - Inide nest1()';
		var a = 'a - Inside nest1(). Hide a of main()';
		console.log('**********next1()****************');
		console.log(a);
		console.log(b);
		function nest2() {
			var c = 'c - Inide nest2()';
			var b = 'b - Inside nest2(). Hide b of nest1()';
			console.log('**********next2()****************');
			console.log(a);
			console.log(b);
			console.log(c);
			function nest3() {
				var d = 'd - Inide nest3()';
				var c = 'c - Inside nest3(). Hide c of nest2()';
				console.log('**********next3()****************');
				console.log(a);
				console.log(b);
				console.log(c);
				console.log(d);
			}
			nest3();
		}
		nest2();
	}
	nest1();
}
main();