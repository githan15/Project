from matplotlib import pyplot
import csv
import random

i = []
lValues = []
with open('LDR.csv', 'r') as f:
	reader = csv.reader(f)
	header = next(reader, None)
	for row in reader:
		i.append(int(row[0]))
		lValues.append(str(row[1]))
pyplot.subplot(2,1,1)
pyplot.plot(i, lValues, '-')
pyplot.title('Line plot -' + header[1])
pyplot.xlim(1,25)
pyplot.xlabel('X Axis')
pyplot.ylabel('Y Axis')


pyplot.tight_layout()
pyplot.show()
