# Develop with STM32CubeIDE

1. This project can be imported to the STM32CubeIDE. Create new project (CTRL+N) and select **Makefile Project with Existing Code**
2. Enter the name, and location of this directory, and select MCU ARM GCC
3. Click **Finish**

The project should be loaded and able to compile. Then you can use it as usual.

## Basic interaction from Linux

The basic configuration of the CAN interface in Linux is done by `ip` command. We need to bring the interface down, then configure it and then bring it up.
This can be done by following the code:

```
dbitrate=2000000
bitrate=1000000
sudo ip link set can0 down
sudo ip link set can1 down
sudo ip link set can0 type can bitrate ${bitrate} fd on dbitrate ${dbitrate}
sudo ip link set can1 type can bitrate ${bitrate} fd on dbitrate ${dbitrate}
sudo ip link set can0 up
sudo ip link set can1 up
```

Then we should be able to send/receive data so we can simulate the traffic by sending custom frames using `cansend` utility,
or by replaying the log using `canplayer`, or generating random traffic using `cangen`.

Some examples of sending data are below:

- `cansend can0 213##311223344`
- `canplayer -I candump.log`
- `cangen can0 -f -b -g 5` or `cangen can0 -c 10 -g 1`

To analyze the bus load we can use `canbusload can0@1000000 can1@1000000 -r -t -b -c` which will each second will compute statistics per interface.
This however works only with standard CAN 2.0 and the CAN FD is not supported.

To display sent data use `candump can0` (it can contain more than one interface so we can use `candump can0 can1` and track the traffic of two interfaces).

## Control of termination resistors

If the `CAN_TERM_FEATURE_ENABLED` feature is enabled, we can enable/disable the termination resistor using the `ip` command. To read the current state we can execute `ip -details link show can0`.
The output will look like this:

```
can0: <NOARP,UP,LOWER_UP,ECHO> mtu 72 qdisc pfifo_fast state UP mode DEFAULT group default qlen 10
    link/can  promiscuity 0 minmtu 0 maxmtu 0
    can <FD> state ERROR-ACTIVE restart-ms 0
          bitrate 1000000 sample-point 0.750
          tq 50 prop-seg 7 phase-seg1 7 phase-seg2 5 sjw 2
          gs_usb: tseg1 1..16 tseg2 1..8 sjw 1..4 brp 1..1024 brp-inc 1
          dbitrate 2000000 dsample-point 0.750
          dtq 25 dprop-seg 7 dphase-seg1 7 dphase-seg2 5 dsjw 2
          gs_usb: dtseg1 1..16 dtseg2 1..8 dsjw 1..4 dbrp 1..1024 dbrp-inc 1
          termination 120 [ 0, 120 ]
          clock 120000000 numtxqueues 1 numrxqueues 1 gso_max_size 65536 gso_max_segs 65535 parentbus usb parentdev 7-1.4.1:1.0
```

Notice the `termination 120 [ 0, 120 ]` line which tells us that the termination resistor is active. To disable it we can run `sudo ip link set dev can0 type can termination 0` and we can check
it was disabled by rerunning the previous command and checking the `termination 0 [ 0, 120 ]` line.

## STM32H745I-DISCO issues

After flashing the board may not be able to connect with the ST-Link GDB server from the IDE. To resolve this we need to delete the firmware from FLASH memory.
This can be done using *STM32CubeProgrammer* by using the GUI or CLI interface. The CLI command looks like this `STM32_Programmer_CLI -c port=SWD mode=POWERDOWN -e All`.
The **POWERDOWN** option is crucial here. Sometimes deleting only the first sector is enough so in the command replace `All` with `0` and the flashing should be fixed too.
