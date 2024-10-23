# Whiteboard Cleaner
* An autonomous whiteboard cleaner is to help the cleaning process. This product has the flexibility to be positioned anywhere within a room and can fit to any size of the board. After  finishing its tasks, the whiteboard can automatically move back to its original position. Which is out of the way when not in use. The application of this design is to save time on the menial tasks such as cleaning a whiteboard. Computer vision, Robotics and Embedded Systems are subjects in electrical engineering that the product relates to.
* System Overview

<img width="500" alt="Screenshot 2024-10-22 at 5 16 50 PM" src="https://github.com/user-attachments/assets/b91991b2-fcbe-487f-83fa-2eb7766503cc">

## Architecture and High Level Design
### System Architecture and Design
  <img width="500" alt="Screenshot 2024-10-22 at 5 18 02 PM" src="https://github.com/user-attachments/assets/bc07e9b8-9baa-4f98-977d-c977c1d5cb7f">

### Hardware Architecture
 <img width="481" alt="Screenshot 2024-10-22 at 5 19 34 PM" src="https://github.com/user-attachments/assets/c8849b34-acb5-4b05-8827-a4abb6f89ede">

### Software Architecture
<img width="518" alt="Screenshot 2024-10-22 at 5 20 24 PM" src="https://github.com/user-attachments/assets/b6a0324e-6c91-4874-b5f5-b5bab0ea067c">

## Low Level Design
### Rover/Arm
<img width="499" alt="Screenshot 2024-10-22 at 5 21 22 PM" src="https://github.com/user-attachments/assets/9d995cfb-f5e4-4c22-b1ce-bd3f535e8889">

<img width="468" alt="Screenshot 2024-10-22 at 5 21 46 PM" src="https://github.com/user-attachments/assets/74aba8ad-84d9-4ca4-a08b-0183acbbe5b0">

* The rover/arm runs by three stepper motors Nema 23 3Nm for x-axis, Nema 23 1.9Nm for y-axis,and Nema 17 13Ncm for z-axis. There are also three ultrasonic sensors communicating with these motors as corresponding feedback; sensor x, y and z. All the controls, functions, and reading the ultrasonic sensor signal are on the Arduino Mega. 

* Switch buttons(power on/off of Aruduino Mega and stepper motor power supply) is the user's input for controlling start/stop the rover/arm movement. User inputs section’s number (calling the function for corresponding cleaning section in Arduino Mega),the rover/arm moves in a preset pattern for each section indicated. 

### Image Processing

<img width="334" alt="Screenshot 2024-10-22 at 5 26 43 PM" src="https://github.com/user-attachments/assets/a04efaf4-8a4c-41fb-a8e0-260c0cfb8be5">

* The image processing starts when receiving a control signal from the user interface via the input button. This action is to tell the matlab to take a picture of the whiteboard by webcam (connect to raspberry pi). After running through the algorithm inside matlab on PC, the array of sections (area on whiteboard go by integer number) are the outputs. The Arduino Mega receives these output arrays from matlab via BT communication. 
* Pushing the button is to start the process. Matlab receives a signal from the button, then calls the function to get a snapshot from the webcam (on raspberry pi). Matlab runs the function read() to get access to the taken picture by raspberry pi. The picture runs into the algorithm for detection. 
* In the detection process, it crops the area of the actual whiteboard in the image and converts it to grayscale image. Then, it divides the cropped image into a number of sections ( which is 12 in the code). These twelves sections will go through the checking pixels. This task checks each of the sections if they contain any of black pixels. By calling the blackpixel() function for each section, if it is true, this section’s number is added to output arrays.


