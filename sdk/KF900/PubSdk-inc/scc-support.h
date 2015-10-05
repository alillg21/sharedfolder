/*
 * Author: 
 *  Owner: KaiFa Technology Corporation.
 *   Date: 2008.01.02
 */
 
#ifndef SCC_SUPPORT_H
#define SCC_SUPPORT_H


#define BUF_LEN         512
#define MAX_BUF_LEN     512
#define MAX_CARD_NUM    6

#define VCC_3V 					0
#define VCC_1_8V 				1
#define VCC_5V 					2

//unsigned char   slotnumber;


/*struct sc_s {
   int           id;            // SC interface number (0-4)
   int	         fd;            // File handle for SC device ( e.g. "/dev/sc0")
} scs[6];
*/

struct scc_cmd
{
    unsigned char   data[BUF_LEN];
    unsigned int   len;	// Length of "data" in byte
    unsigned char   name[64];
}__attribute__ ((packed));


//extern int      scc_filedesc;	// file descriptor for POSIX standard I/O operation 


extern int      scc_init(void);	/* SmartCard initialization */
extern void     scc_fini(void);

extern int      scc_select_slot(unsigned char slot);	/* Choose a slot to operate */
extern unsigned char inserted_card(void); //�忨-0 δ�忨-1

extern int      scc_reset(unsigned char *voltage, unsigned char *atr, unsigned int *len);	/* Reset and get the ATR */

/*Ϊ�˼��ݣ����Ѱ���T1,����scc_command_APDUһ����֧��T0,T1Э��*/
extern int SendCmdT0_APDU(struct scc_cmd *command, unsigned char *rbuf,unsigned int *rlen);

extern int scc_command_APDU(struct scc_cmd *command, unsigned char *rbuf, unsigned int *rlen);

extern int scc_close(void);

#endif /*  SCC_SUPPORT_H  */
