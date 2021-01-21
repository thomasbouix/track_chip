# Altimètre BMP180

## BUS I2C
```
Deux fils (SDA, SCL) tirés à 5V.

I2C utilise des séquences de 8 bits (MSB first = Big Endian)

Start - slave_addr - A - slave_reg - A - Data - A - Stop

Start	: SDA drops low, SDC still high
ACK	: le slave tire la ligne SDA à zéro
Stop 	: SDA low -> high ; SCL high
```
## Librairie utilisée
```
https://bitbucket.org/christandlg/bmp180mi/src/master/
```

