def main():
	a = 'a - Inide main()'
	print('**********main()****************')
	print(a)
	def nest1():
		b = 'b - Inide nest1()'
		a = 'a - Inside nest1(). Hide a of main()'
		print('**********next1()****************')
		print(a)
		print(b)
		def nest2():
			c = 'c - Inide nest2()'
			b = 'b - Inside nest2(). Hide b of nest1()'
			print('**********next2()****************')
			print(a)
			print(b)
			print(c)
			def nest3():
				d = 'd - Inide nest3()'
				c = 'c - Inside nest3(). Hide c of nest2()'
				print('**********next3()****************')
				print(a)
				print(b)
				print(c)
				print(d)
			nest3()
		nest2()
	nest1()
main()