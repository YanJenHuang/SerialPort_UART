# SERIAL PORT-UART
##### This repository contains two files:
1. SerialPort_Read: Receive char via RX
2. SerialPort_Write: Transmit char via TX
 
I simply test it on my "BeagleBone Black" as Transmitter and my Mac as Receiver.

#### There are three steps to set up the Mac environment:
>1. Download and Install the driver: FTDI USB Serial
>2. After installing the correct driver, plug in your USB-Serial adapter.
>3. Open the <strong>Terminal</strong> and Enter:<code>ls /dev/cu.*</code>
>>You will See 
>>><code>$ ls /dev/cu.*
/dev/cu.Bluetooth-Modem		/dev/cu.Bluetooth-Incoming-Port
<strong>/dev/cu.usbserial</strong></code>
something like <code><strong>/dev/cu.usbserial</strong></code> will show up.
This indicates the USB-Serial driver is working! Congratulation!

#### BeagleBone Black:
>1. Enable the UART1:
>> Enter: <code>echo BBUART1 > /sys/devices/bone_capemgr.*/slots</code>

>2. Enter: <code>ls /dev/ttyO*</code>
>>You should see 
>><code>$ ls /dev/ttyO*
/dev/ttyO0		<strong>/dev/ttyO1</strong></code>
>>><code><strong>/dev/ttyO1</strong></code> should show up.

>3. Now you can use your <strong>P9.24(UART1_TX), and P9.26(UART_RX).</strong>
>>Notes: I only use P9.24 as Transmitter here.

#### Copy the files and testing.
>1. Mac: SerialPort_Read.cpp
>2. BBB: SerialPort_Write.cpp
