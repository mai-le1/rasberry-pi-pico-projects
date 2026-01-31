## Part of the main code I worked on that control the movements and the object detectors

distance_1 = sensor1.distance_cm() 
distance_2 = sensor2.distance_cm() 
distance_3 = sensor3.distance_cm() 
 
print(f"Distance 1: {distance_1} cm, Distance 2: {distance_2} cm, Distance 3: {distance_3} cm") 
 
sleep(0.1) 
 
 
# If obstacles are found on both the front and right side 
if distance_1 <= 15 and distance_2 <= 15 and distance_1 > 0 and distance_2 > 0: 
    reverse(35, 0.3) 
    left_turn(35, 0.495)  # Turn left 
    print("front, right") 
# If obstacles are found on both the front and left side 
elif distance_1 <= 15 and distance_3 <= 15 and distance_1 >0 and distance_3 > 0: 
    reverse(35, 0.3) 
    right_turn(35, 0.485)  # Turn right  
    print("front, left") 
     
# If an obstacle is found on the right only 
elif distance_2 <= 20 and distance_2 > 0:  
    print("Right") 
    while distance_2 <= 20 and distance_2 > 0:  
        drive(40, 0.2)  # Go straight 
        distance_1 = sensor1.distance_cm() 
        distance_2 = sensor2.distance_cm() 
        distance_3 = sensor3.distance_cm() 
        if distance_1 <= 20 and distance_1 > 0: 
            print("sees in front") 
            reverse(35, 0.2) 
            left_turn(35, 0.495) 
            break 
    else: 
        print("else turns right") 
        drive(40,0.2) 
        right_turn(40,0.1) 
        continue 
 
# If an obstacle is found on the left only 
elif (distance_3 <= 20 and distance_3 > 0):   
    while distance_3 <= 20 and distance_3 > 0:  
        drive(40, 0.2)  # Go straight 
        distance_1 = sensor1.distance_cm() 
        distance_2 = sensor2.distance_cm() 
        distance_3 = sensor3.distance_cm() 
        print("Left") 
        print(f"Distance 1: {distance_1} cm, Distance 2: {distance_2} cm, Distance 3: {distance_3} cm") 
         
        if distance_1 <= 20 and distance_1 > 0: 
            print("sees in front") 
            reverse(35, 0.2) 
            right_turn(35, 0.485) 
             
            break 
    else: 
        print("else turn left") 
        drive(40,0.2) 
        left_turn(40,0.1) 
        continue 
 
 
# If obstacles are detected on all sides 
elif distance_2 <= 15 and distance_1 <= 15 and distance_1 > 0 and distance_3 <= 15 and distance_2 >0 and distance_3 > 0: 
    while True: 
        distance_1 = sensor1.distance_cm() 
        distance_2 = sensor2.distance_cm() 
        distance_3 = sensor3.distance_cm() 
         
        if distance_2 <= 15 and distance_2 >0 and distance_3 <= 15 and distance_3 > 0: 
            reverse(35, 1.5)  # Move backward to avoid both obstacles 
            print("Reverse") 
             
        else: 
            right_turn(35, 0.485) 
            drive(40, 0.3) 
            left_turn(35, 0.495) 
            print("after reverse") 
            break 
  # If an obstacle is detected in front 
elif distance_1 <= 15 and distance_1 > 0: 
    reverse(35, 0.1) 
    right_turn(35, 0.495)  # Turn right  
    print("front") 
# If no obstacle is detected 
 
else: 
    drive(40, 0.5)  # Go straight 
    print("Go straight")
