import serial
import Tkinter

arduinoData = serial.Serial('/dev/ttyACM1', 9600)

def ledp_On():
	arduinoData.write('1')
def ledp_Off():
	arduinoData.write('2')
def rgb_On():
	arduinoData.write('3')
def rgb_Off():
	arduinoData.write('4')
def musik_On():
	arduinoData.write('5')
def musik_Off():
	arduinoData.write('6')

led = Tkinter.Tk()
Button = Tkinter.Button

btn = Button(led, text="led putih Menyala Semua", command=ledp_On)
btn1 = Button(led, text="led RGB Menyala Semua", command=rgb_On)
btn2 = Button(led, text="Led Putih Mati Semua", command=ledp_Off)
btn3 = Button(led, text="Led RGB Mati Semua", command=rgb_Off)
btn4 = Button(led, text="Musik Menyala", command=musik_On)
btn5 = Button(led, text="Musik Mati", command=musik_Off)

btn.grid(row=0, column=1)
btn1.grid(row=0, column=2)
btn2.grid(row=1, column=1)
btn3.grid(row=1, column=2)
btn4.grid(row=0, column=3)
btn5.grid(row=1, column=3)

led.mainloop()

input("Press Enter to Exit...")
