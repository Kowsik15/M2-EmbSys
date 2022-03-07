# Smart-ECG-alert-system
Heart attack alert system for hospitals
Cost efficient as it can manage all the patients present in 100 meters range
We need only one GSM module for alering about all the patints available in that range


# setting up and using 
initially we need to enter the contact number of the doctor using the keypad present in the receiver having gsm module on which the alert message will be sent and we are good to go thereafter


# NRF24L01
the nrf24l01 is a radio frequency transreceiver used for communication between the transmitter ans receiver
It works on SPI communication protocol
Since proteus has no such library of NRF24L01 so for simulaton purposes both the transmitter's and the receiver's SPI pins (MISO, MOSI, SCK and SS) have been connected with each other through wires depicting the presence of NRF24L01


# Main working Idea
The main woring idea behind the model is that there chances for a person to face heart attack if his heart beat goes below 60 b.p.m. or above 100 b.p.m.

