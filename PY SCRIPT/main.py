# This is a sample Python script.
import serial

# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    com = input("Enter your Com Port Number : ")

    ser = serial.Serial(
        port='COM' + str(com),
        baudrate=9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=15)

    file = open("LED_ROLL.hex", "r")
    rec = 1

    while True:
        line = file.readline()
        line = line.replace(':', '', -1)

        for x in range(len(line)):
            char = line[x]
            ser.write(char.encode())

        print('Sent Record No :: ' + str(rec))
        rec = rec + 1
        data = ser.read(1)

        if data == b'D':
            continue
        if data == b'F':
            break
        if data == b'E':
            print('RECORD CORRUPTION ...')
            break

    ser.close()

    print('Flashing Is Done...')



