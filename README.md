# CAN Project Template for STM32F103
---

<h4>

Before using the project, kindly go through the CAN driver. The project is 
created using STM32CubeIDE so that it can be further customized. The console
driver and GPIO driver is also written in bare metal C. 

The implementation is straightforward. Go through main.c to understand how 
to use the driver.
CAN driver needs the following struct typedefs for configuration, transmission and reception of messages ,and filter initialzation. 

```C
CAN_TX_Typedef TX;
CAN_RX_Typedef RX;
CAN_Filter_TypeDef filter;
CAN_Init_Typedef CAN;
```

CAN initialization is as simple as the following 4 lines 
of code. Baudrate can be changed based by changing the macros. For the complete list of macros. Beware, the baudrate is dependent on the internal clock. If there is any discrepancy in the system clock, it'll also affect
baudrate. This implementation of CAN driver utilizes CAN receive interrrupts because of which the application dosen't have to wait to receive
and messages and cater to incoming messages as they come. Once done, pass 
the structure into the CAN_Init() function. CAN_Init is declared in CAN folder.

```C
  CAN.CAN_INSTANCE = CAN1;
  CAN.baudrate = CAN_BAUDRATE_1000_KBPS;
  CAN.interrupt = Fifo0_Message_Pending;
  CAN_Init(&CAN);
```

CAN Filter initialzation is again a breeze with this driver implementation. Just insert what CAN-ID you want the filter to be initialized as, select one of the 12 CAN hardware message filters by passing the number in filter_id, type of CAN ID type and frame type you're looking for. Once done, pass the CAN and filter typedefs in CAN_Filter_Init().
```C
  filter.ID = 0x00;
  filter.filter_id = 0;
  filter.id_type = CAN_ID_Standard;
  filter.frame_type = CAN_Frame_Remote;
  CAN_Filter_Init(&CAN, &filter);
```

Once Basic and Filter Initialzation is done, Start the CAN Hardware Block. by calling CAN_Start() function. Go through main.c to get a clear picture. 

If you have any any issues with the implementation, working, or any other issues with the project, please don't hesitate to raise an issue on the repo. I'll get back to you as soon as I can 😁. 

Happy Coding !!

</h4>