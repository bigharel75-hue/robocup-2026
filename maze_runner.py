colors = []
turnCounter = 0
def color():
    if color_sensor_in1.color != 6 and not color_sensor_in1.color in colors:
        colors.append(color_sensor_in1.color)
        print("seen",color_sensor_in1.color_name)
        if sorted(colors) == [2,3,4,5]:
            print("finished")
            quit()
def turn():
    while gyro_sensor_in5.angle != turnCounter:
        tank_drive.on((100 if 100 < turnCounter - gyro_sensor_in5.angle else (-100 if -100 > turnCounter - gyro_sensor_in5.angle else turnCounter - gyro_sensor_in5.angle)), 0)
def drive():
    while ultrasonic_sensor_in2.distance_centimeters > 25.6:
        tank_drive.on((100 if 100 < ultrasonic_sensor_in2.distance_centimeters - 24 else(-100 if -100 > turnCounter - gyro_sensor_in5.angle else ultrasonic_sensor_in2.distance_centimeters - 24)), (100 if 100 < ultrasonic_sensor_in2.distance_centimeters - 24 else(-100 if -100 > turnCounter - gyro_sensor_in5.angle else ultrasonic_sensor_in2.distance_centimeters - 24)))
    tank_drive.off(brake=True)
while True:
    color()
    drive()
    color()
    tank_drive.on_for_degrees(40, 0, 500)
    turnCounter+=90
    if ultrasonic_sensor_in2.distance_centimeters < 15.6:
        tank_drive.on_for_degrees(-40, 0, 500)
        tank_drive.on_for_degrees(0, 40, 500)
        turnCounter-=180
        if ultrasonic_sensor_in2.distance_centimeters < 15.6:
            tank_drive.on_for_degrees(-40, 0, 500)
            turnCounter+=90
    color()
    turn()
