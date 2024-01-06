
import serial
import psutil
import time

ser = serial.Serial('COM4', 9600)

while True:
    cpu_percent = psutil.cpu_percent()
    memory_info = psutil.virtual_memory()
    memory_unused = round(memory_info.available / (1024 * 1024 * 1024))
    used_memory = round(memory_info.used / (1024 * 1024 * 1024), 1)
    
    data = f"CPU: {cpu_percent}%|Memory unused: {memory_unused} Gb|Memory usage: {used_memory} Gb"
    ser.write(data.encode())
    time.sleep(0.5)
