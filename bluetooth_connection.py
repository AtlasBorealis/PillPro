import serial
import tkinter as tk

# establish serial connection to Arduino
ser = serial.Serial('COM6', 115200) # check port in BT SETTINGS, 115200 BAUD 
led_status = False

def send_code():
    global led_status
    code = int(code_entry.get())
    code_entry.delete(0, 'end')
    ser.write(str(code).encode())
    response = ser.readline().decode().rstrip()
    if response == 'Correct code!':
        if not led_status:
            #ser.write(b'1\n') # turn on the LED
            led_status = True
            status_label.config(text='LED is ON')
    else:
        if led_status:
            #ser.write(b'0\n') # turn off the LED
            led_status = False
            status_label.config(text='LED is OFF')

def clear_entries():
    global led_status
    code_entry.delete(0, 'end')
    #ser.write(b'0\n') # turn off the LED
    led_status = False
    status_label.config(text='LED is OFF')

root = tk.Tk()
root.title('LED Control')
root.geometry('300x200')
root.resizable(False, False)

# create main frame
frame = tk.Frame(root, bg='#f5f5f5', padx=10, pady=10)
frame.pack(expand=True, fill='both')

# create label and entry for entering code
code_label = tk.Label(frame, text='Enter Alarm Time HERE:', font=('Arial', 12), bg='#f5f5f5')
code_label.pack()
code_entry = tk.Entry(frame, font=('Arial', 12), bg='#fff', width=20)
code_entry.pack(pady=10)

# create button for sending code
send_button = tk.Button(frame, text='Save', font=('Arial', 12), bg='#0077ff', fg='#fff', width=10, command=send_code)
send_button.pack(pady=10)

# create label for displaying status
status_label = tk.Label(frame, text='Press SAVE to send code', font=('Arial', 12), bg='#f5f5f5')
status_label.pack()

# start GUI loop
root.mainloop()

# close serial
ser.close()