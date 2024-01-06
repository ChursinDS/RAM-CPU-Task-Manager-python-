 
import serial
import psutil
import time

ser = serial.Serial('COM4', 9600)  # 

while True:
    cpu_percent = psutil.cpu_percent()
    memory_info = psutil.virtual_memory()
    available_memory = memory_info.available / (1024 * 1024 * 1024)
    used_memory = memory_info.used / (1024 * 1024 * 1024)

    data = f"CPU: {cpu_percent}|MEM: {available_memory}|{used_memory}"
    ser.write(data.encode())

    time.sleep(1)
