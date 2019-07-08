Generic mynewt device application example

This is the main() device application that uses the app-core system to create a basic LoRa device.
It depends on the v1.6.0 mynewt-core (with an STM32L1 SPI patch), the wyres BSP / mynewt-generic-base / mynewt-generic-app projects, and the lorawan wrapper for mynewt. 
!! currently the github project for the lorawan wrapper is not up to date !!

It defines 2 targets:
 - the bootloader : "wbase_revC_bootloader"
newt clean wbase_revC_bootloader
newt build wbase_revC_bootloader
newt load wbase_revC_bootloader

 - application : "wbase_revC_gpstest"
newt clean wbase_revC_gpstest
newt build wbase_revC_gpstest
newt create-image -2 wbase_revC_gpstest 1.0.0
newt load wbase_revC_gpstest
_or_
newt run -2 wbase_revC_gpstest 1.0.0 --noGDB

 
