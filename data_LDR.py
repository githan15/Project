import csv
import pyfirmata
from time import sleep

port = "/dev/ttyACM0"
board = pyfirmata.Arduino(port)

it = pyfirmata.util.Iterator(board)
it.start()
a4 = board.get_pin('a:4:i')

with open('LDR.csv', 'w') as f:
	w = csv.writer(f)
	w.writerow(["No", "LDR sensor"])
	i = 0
	LDRData = a4.read()
	while i<25:
		LDRData = a4.read()
		print(i, LDRData)
		print i
		sleep(1)
		i += 1
		row = [i, LDRData]
		w.writerow(row)
	print "File CSV Telah Tersedia!"
board.exit()
