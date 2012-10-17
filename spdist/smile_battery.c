/*i2c_test.c
 * hongtao_liu <lht@farsight.com.cn>
 * Modified by truedat101 <dkords@gmail.com> Razortooth Communications, LLC
 * 
 * License is TBD - DO NOT DISTRIBUTE
 * 2012(c) GTI
*/
#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#define I2C_RETRIES 0x0701
#define I2C_TIMEOUT 0x0702
#define I2C_RDWR 0x0707
        /********* *******/
struct i2c_msg
        {
			unsigned short addr;
			unsigned short flags;
			#define I2C_M_TEN 0x0010
			#define I2C_M_RD 0x0001
			#define I2C_M_NOSTART		0x4000	/* if I2C_FUNC_PROTOCOL_MANGLING */
			#define I2C_M_REV_DIR_ADDR	0x2000	/* if I2C_FUNC_PROTOCOL_MANGLING */
			#define I2C_M_IGNORE_NAK	0x1000	/* if I2C_FUNC_PROTOCOL_MANGLING */
			#define I2C_M_NO_RD_ACK		0x0800	/* if I2C_FUNC_PROTOCOL_MANGLING */
			#define I2C_M_RECV_LEN		0x0400	/* length will be first received byte */
			unsigned short len;
			unsigned char *buf;
        };
		
struct i2c_rdwr_ioctl_data
        {
			struct i2c_msg *msgs;
			int nmsgs;
        };

        int main(int argc, char** argv)
        {
            int fd,ret;
            struct i2c_rdwr_ioctl_data e2prom_data;

            fd=open("/dev/i2c-0",O_RDWR);
    
   
            if(fd<0)
            {
				perror("open error");
            }
            e2prom_data.nmsgs=2;

            e2prom_data.msgs=(struct i2c_msg*)malloc(e2prom_data.nmsgs*sizeof(struct i2c_msg));
            if(!e2prom_data.msgs)
            {
				perror("malloc error");
				exit(1);
            }
            ioctl(fd,I2C_TIMEOUT,1);
            ioctl(fd,I2C_RETRIES,2);

			printf("test i2c by steven\n");
            /***write data to e2prom**/

            e2prom_data.nmsgs=1;
            (e2prom_data.msgs[0]).len=2; 

            (e2prom_data.msgs[0]).addr=0x0B;
            (e2prom_data.msgs[0]).flags=0; //write
            (e2prom_data.msgs[0]).buf=(unsigned char*)malloc(2);
            (e2prom_data.msgs[0]).buf[0]=0x8;// e2prom 
            (e2prom_data.msgs[0]).buf[1]=0x0;//the data to write
			ret=ioctl(fd,I2C_RDWR,(unsigned long)&e2prom_data);
			
            if(ret<0)
            {
				perror("ioctl error1");
            }
            
            
    /******read voltage data from e2prom*******/
            e2prom_data.nmsgs=2;
			printf("test00 i2c by steven\n");
            (e2prom_data.msgs[0]).len=1; //e2prom 
            (e2prom_data.msgs[0]).addr=0x0b; // e2prom
            (e2prom_data.msgs[0]).flags=0;//write
            (e2prom_data.msgs[0]).buf[0]=0x09; //e2prom

            (e2prom_data.msgs[1]).len=2;

			printf("test01 i2c by steven\n");

            (e2prom_data.msgs[1]).addr=0x0b;// e2prom
            (e2prom_data.msgs[1]).flags=I2C_M_RD;//read

            (e2prom_data.msgs[1]).buf=(unsigned char*)malloc(2);
            (e2prom_data.msgs[1]).buf[0]=0;
            (e2prom_data.msgs[1]).buf[1]=0; 
			printf("test2 i2c by steven\n");
			ret=ioctl(fd,I2C_RDWR,(unsigned long)&e2prom_data);
			printf("test3 i2c by steven\n");
            if(ret<0)
            {
				perror("ioctl error2");
            }
            printf("voltage buff[0]=%x\n",(e2prom_data.msgs[1]).buf[0]);
            printf("voltage buff[1]=%x\n",(e2prom_data.msgs[1]).buf[1]);


    /******read manufacture data from e2prom*******/
            e2prom_data.nmsgs=2;
            (e2prom_data.msgs[0]).len=1; //e2prom
            (e2prom_data.msgs[0]).addr=0x0b; // e2prom 
            (e2prom_data.msgs[0]).flags=0;//write
            (e2prom_data.msgs[0]).buf[0]=0x00; //e2prom
            (e2prom_data.msgs[1]).len=1;//
            
            (e2prom_data.msgs[1]).addr=0x0b;// e2prom
            (e2prom_data.msgs[1]).flags=I2C_M_RD;//read
            (e2prom_data.msgs[1]).buf=(unsigned char*)malloc(1);
            (e2prom_data.msgs[1]).buf[0]=0; 
			ret=ioctl(fd,I2C_RDWR,(unsigned long)&e2prom_data);
            if(ret<0)
            {
				perror("ioctl error2");
            }
            printf("buff[0]=%x\n",(e2prom_data.msgs[1]).buf[0]);

           sleep(1);

    /******read remainingcapacity data from e2prom*******/
            e2prom_data.nmsgs=2;
            (e2prom_data.msgs[0]).len=1; //e2prom 
            (e2prom_data.msgs[0]).addr=0x0b; // e2prom
            (e2prom_data.msgs[0]).flags=0;//write
            (e2prom_data.msgs[0]).buf[0]=0x0f; //e2prom

            (e2prom_data.msgs[1]).len=2;
            
            (e2prom_data.msgs[1]).addr=0x0b;// e2prom
            (e2prom_data.msgs[1]).flags=I2C_M_RD;//read

            (e2prom_data.msgs[1]).buf=(unsigned char*)malloc(2);
            (e2prom_data.msgs[1]).buf[0]=0; 
            (e2prom_data.msgs[1]).buf[1]=0;
			ret=ioctl(fd,I2C_RDWR,(unsigned long)&e2prom_data);
            if(ret<0)
            {
				perror("ioctl error2");
            }
            printf("remainingcapacity buff[0]=%x\n",(e2prom_data.msgs[1]).buf[0]);
            printf("remainingcapacity buff[1]=%x\n",(e2prom_data.msgs[1]).buf[1]);

            close(fd);
            return 0;
        }
