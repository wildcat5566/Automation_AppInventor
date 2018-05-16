import pymysql
import serial
db = pymysql.connect("localhost","newuser","lab301","newdb")
cursor = db.cursor()

cursor.execute("SELECT id, color FROM Client_info WHERE color != 0")
row = cursor.fetchone()
print (row[0], row[1])
client = row[0]
merchandise = row[1]

cursor.execute("UPDATE Client_info SET send_status=1 WHERE color != 0")
db.commit()

ser = serial.Serial('/dev/ttyACM0', 9600)
def sendMsg(_client, _merchandise):
	msg = (str(_client)+str(_merchandise)).encode('utf-8')
	ser.write(msg)

sendMsg(client, merchandise)
recvMsg = ser.readline().decode('utf-8')
print(recvMsg)

cursor.close()
db.close()
