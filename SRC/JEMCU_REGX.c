// ePWM top ext Ram =======================================
unsigned char xdata PCLKCR _at_ 0xe000;
unsigned char xdata PSYNCICR _at_ 0xe001;
	
// ePWM1 ext Ram ==========================================
unsigned char xdata P1TBCTL_L	_at_ 0xe002; 
unsigned char xdata P1TBCTL_H	_at_ 0xe003;
unsigned char xdata 	P1TBSTS		_at_ 0xe004;
unsigned char xdata 	P1TBCTR_L	_at_ 0xe005;
unsigned char xdata 	P1TBCTR_H 	_at_ 0xe006;
unsigned char xdata 	P1CMPCTL	_at_ 0xe007;
unsigned char xdata 	P1AQCTLA_L	_at_ 0xe008;
unsigned char xdata 	P1AQCTLA_H	_at_ 0xe009;
unsigned char xdata 	P1AQCTLB_L	_at_ 0xe00a;
unsigned char xdata 	P1AQCTLB_H	_at_ 0xe00b;
unsigned char xdata 	P1DBCTL		_at_ 0xe00c;
unsigned char xdata 	P1DBRED_L	_at_ 0xe00d;
unsigned char xdata 	P1DBRED_H	_at_ 0xe00e;
unsigned char xdata 	P1DBFED_L	_at_ 0xe00f;
unsigned char xdata 	P1DBFED_H	_at_ 0xe010;
unsigned char xdata 	P1TZSEL		_at_ 0xe011;
unsigned char xdata 	P1TZCTL		_at_ 0xe012;
unsigned char xdata 	P1TZEINT	_at_ 0xe013;
unsigned char xdata 	P1ETSEL_L	_at_ 0xe014;
unsigned char xdata 	P1ETSEL_H	_at_ 0xe015;
unsigned char xdata 	P1ETPS_L	_at_ 0xe016;
unsigned char xdata 	P1ETPS_H	_at_ 0xe017;
unsigned char xdata 	P1TBPHS_L	_at_ 0xe0b6; 
unsigned char xdata 	P1TBPHS_H	_at_ 0xe0b7;
	
// ePWM2 ext Ram ==========================================
unsigned char xdata 	P2TBCTL_L	_at_ 0xe018; 
unsigned char xdata 	P2TBCTL_H	_at_ 0xe019;
unsigned char xdata 	P2TBSTS		_at_ 0xe01a;
unsigned char xdata 	P2TBCTR_L	_at_ 0xe01b;
unsigned char xdata 	P2TBCTR_H 	_at_ 0xe01c;
unsigned char xdata 	P2CMPCTL	_at_ 0xe01d;
unsigned char xdata 	P2AQCTLA_L	_at_ 0xe01e;
unsigned char xdata 	P2AQCTLA_H	_at_ 0xe01f;
unsigned char xdata 	P2AQCTLB_L	_at_ 0xe020;
unsigned char xdata 	P2AQCTLB_H	_at_ 0xe021;
unsigned char xdata 	P2DBCTL		_at_ 0xe022;
unsigned char xdata 	P2DBRED_L	_at_ 0xe023;
unsigned char xdata 	P2DBRED_H	_at_ 0xe024;
unsigned char xdata 	P2DBFED_L	_at_ 0xe025;
unsigned char xdata 	P2DBFED_H	_at_ 0xe026;
unsigned char xdata 	P2TZSEL		_at_ 0xe027;
unsigned char xdata 	P2TZCTL		_at_ 0xe028;
unsigned char xdata 	P2TZEINT	_at_ 0xe029;
unsigned char xdata 	P2ETSEL_L	_at_ 0xe02a;
unsigned char xdata 	P2ETSEL_H	_at_ 0xe02b;
unsigned char xdata 	P2ETPS_L	_at_ 0xe02c;
unsigned char xdata 	P2ETPS_H	_at_ 0xe02d;
unsigned char xdata 	P2TBPHS_L	_at_ 0xe0b8; 
unsigned char xdata 	P2TBPHS_H	_at_ 0xe0b9;
	
// ePWM3 ext Ram ==========================================
unsigned char xdata 	P3TBCTL_L	_at_ 0xe02e; 
unsigned char xdata 	P3TBCTL_H	_at_ 0xe02f;
unsigned char xdata 	P3TBSTS		_at_ 0xe030;
unsigned char xdata 	P3TBCTR_L	_at_ 0xe031;
unsigned char xdata 	P3TBCTR_H 	_at_ 0xe032;
unsigned char xdata 	P3CMPCTL	_at_ 0xe033;
unsigned char xdata 	P3AQCTLA_L	_at_ 0xe034;
unsigned char xdata 	P3AQCTLA_H	_at_ 0xe035;
unsigned char xdata 	P3AQCTLB_L	_at_ 0xe036;
unsigned char xdata 	P3AQCTLB_H	_at_ 0xe037;
unsigned char xdata 	P3DBCTL		_at_ 0xe038;
unsigned char xdata 	P3DBRED_L	_at_ 0xe039;
unsigned char xdata 	P3DBRED_H	_at_ 0xe03a;
unsigned char xdata 	P3DBFED_L	_at_ 0xe03b;
unsigned char xdata 	P3DBFED_H	_at_ 0xe03c;
unsigned char xdata 	P3TZSEL		_at_ 0xe03d;
unsigned char xdata 	P3TZCTL		_at_ 0xe03e;
unsigned char xdata 	P3TZEINT	_at_ 0xe03f;
unsigned char xdata 	P3ETSEL_L	_at_ 0xe040;
unsigned char xdata 	P3ETSEL_H	_at_ 0xe041;
unsigned char xdata 	P3ETPS_L	_at_ 0xe042;
unsigned char xdata 	P3ETPS_H	_at_ 0xe043;
unsigned char xdata 	P3TBPHS_L	_at_ 0xe0ba; 
unsigned char xdata 	P3TBPHS_H	_at_ 0xe0bb;
	
// ePWM4 ext Ram ==========================================
unsigned char xdata 	P4TBCTL_L	_at_ 0xe044; 
unsigned char xdata 	P4TBCTL_H	_at_ 0xe045;
unsigned char xdata 	P4TBSTS		_at_ 0xe046;
unsigned char xdata 	P4TBCTR_L	_at_ 0xe047;
unsigned char xdata 	P4TBCTR_H 	_at_ 0xe048;
unsigned char xdata 	P4CMPCTL	_at_ 0xe049;
unsigned char xdata 	P4AQCTLA_L	_at_ 0xe04a;
unsigned char xdata 	P4AQCTLA_H	_at_ 0xe04b;
unsigned char xdata 	P4AQCTLB_L	_at_ 0xe04c;
unsigned char xdata 	P4AQCTLB_H	_at_ 0xe04d;
unsigned char xdata 	P4DBCTL		_at_ 0xe04e;
unsigned char xdata 	P4DBRED_L	_at_ 0xe04f;
unsigned char xdata 	P4DBRED_H	_at_ 0xe050;
unsigned char xdata 	P4DBFED_L	_at_ 0xe051;
unsigned char xdata 	P4DBFED_H	_at_ 0xe052;
unsigned char xdata 	P4TZSEL		_at_ 0xe053;
unsigned char xdata 	P4TZCTL		_at_ 0xe054;
unsigned char xdata 	P4TZEINT	_at_ 0xe055;
unsigned char xdata 	P4ETSEL_L	_at_ 0xe056;
unsigned char xdata 	P4ETSEL_H	_at_ 0xe057;
unsigned char xdata 	P4ETPS_L	_at_ 0xe058;
unsigned char xdata 	P4ETPS_H	_at_ 0xe059;
unsigned char xdata 	P4TBPHS_L	_at_ 0xe0bc; 
unsigned char xdata 	P4TBPHS_H	_at_ 0xe0bd;

// ADC ext Ram ==========================================
unsigned char xdata   ADCTL     _at_ 0xe05a;
volatile unsigned char xdata   ADFLG     _at_ 0xe05b;
unsigned char xdata   ADCHS     _at_ 0xe05c;
unsigned char xdata   ADSHBP    _at_ 0xe05d;
unsigned char xdata   AD1OST_L  _at_ 0xe05e;
unsigned char xdata   AD1OST_H  _at_ 0xe05f;
unsigned char xdata   AD2OST_L  _at_ 0xe060;
unsigned char xdata   AD2OST_H  _at_ 0xe061;
unsigned char xdata   AD3OST_L  _at_ 0xe062;
unsigned char xdata   AD3OST_H  _at_ 0xe063;
unsigned char xdata   AD4OST_L  _at_ 0xe064;
unsigned char xdata   AD4OST_H  _at_ 0xe065;
unsigned char xdata   AD5OST_L  _at_ 0xe066;
unsigned char xdata   AD5OST_H  _at_ 0xe067;
unsigned char xdata   AD6OST_L  _at_ 0xe068;
unsigned char xdata   AD6OST_H  _at_ 0xe069;
unsigned char xdata   AD7OST_L  _at_ 0xe06a;
unsigned char xdata   AD7OST_H  _at_ 0xe06b;
unsigned char xdata   AD1OUT_L  _at_ 0xe06c;
unsigned char xdata   AD1OUT_H  _at_ 0xe06d;
unsigned char xdata   AD2OUT_L  _at_ 0xe06e;
unsigned char xdata   AD2OUT_H  _at_ 0xe06f;
unsigned char xdata   AD3OUT_L  _at_ 0xe070;
unsigned char xdata   AD3OUT_H  _at_ 0xe071;
unsigned char xdata   AD4OUT_L  _at_ 0xe072;
unsigned char xdata   AD4OUT_H  _at_ 0xe073;
unsigned char xdata   AD5OUT_L  _at_ 0xe074;
unsigned char xdata   AD5OUT_H  _at_ 0xe075;
unsigned char xdata   AD6OUT_L  _at_ 0xe076;
unsigned char xdata   AD6OUT_H  _at_ 0xe077;
unsigned char xdata   AD7OUT_L  _at_ 0xe078;
unsigned char xdata   AD7OUT_H  _at_ 0xe079;
unsigned char xdata   ADCISEL   _at_ 0xe0be;

// DAC ext Ram ==========================================
unsigned char xdata   DAC_CON   _at_ 0xe07a;
unsigned char xdata   DAC0_data _at_ 0xe07b;
unsigned char xdata   DAC1_data _at_ 0xe07c;

// SPI ext Ram ==========================================
unsigned char xdata   SPCON     _at_ 0xe07d;
unsigned char xdata   SPSTA     _at_ 0xe07e;
unsigned char xdata   SPDAT     _at_ 0xe07f;

// I2C ext Ram ==========================================
unsigned char xdata   I2CDATA   _at_ 0xe080;
unsigned char xdata   I2CSTATUS _at_ 0xe081;
unsigned char xdata   I2CCLK    _at_ 0xe082;
unsigned char xdata   I2CTIMER  _at_ 0xe083;
unsigned char xdata   I2CON     _at_ 0xe084;
unsigned char xdata   I2CADDR   _at_ 0xe085;

// TEMP ext Ram ==========================================
unsigned char xdata   TEMPS_CON _at_ 0xe086;

// LVD ext Ram ==========================================
unsigned char xdata   LVD_CON   _at_ 0xe087;

// TIMER34 ext Ram reserved========================================
unsigned char xdata   TL3       _at_ 0xe088;
unsigned char xdata   TH3       _at_ 0xe089;
unsigned char xdata   TL4       _at_ 0xe08a;
unsigned char xdata   TH4       _at_ 0xe08b;
unsigned char xdata   Tcon_34   _at_ 0xe08c;
unsigned char xdata   Tmode_34  _at_ 0xe08d;

// MTP ext Ram ==========================================
unsigned char xdata   MTPCON1   _at_ 0xe08e;
unsigned char xdata   MTPCON2   _at_ 0xe08f;
unsigned char xdata   MTPCON3   _at_ 0xe090;
unsigned char xdata   MTPSADD1  _at_ 0xe091;
unsigned char xdata   MTPSADD2  _at_ 0xe092;
unsigned char xdata   MTPDADD1  _at_ 0xe093;
unsigned char xdata   MTPDADD2  _at_ 0xe094;
unsigned char xdata   MTPDADD3  _at_ 0xe095;
unsigned char xdata   MTPDADD4  _at_ 0xe096;

// CURRENT REF ext Ram ==========================================
unsigned char xdata   CREF_CON  _at_ 0xe097;
unsigned char xdata   VBG_TUNE  _at_ 0xe098;
unsigned char xdata   VREF_TUNE _at_ 0xe099;
unsigned char xdata   IREF_TUNE _at_ 0xe09a;

// LDO ext Ram ==========================================
unsigned char xdata   LDO_V18   _at_ 0xe09b;
unsigned char xdata   LDO_V25   _at_ 0xe09c;
unsigned char xdata   LDO_CON   _at_ 0xe09d;

// XTAL ext Ram ==========================================
unsigned char xdata   XTAL_CON  _at_ 0xe09e;

// RTC ext Ram ==========================================
unsigned char xdata   RTCCTRL   _at_ 0xe09f;
unsigned char xdata   RTCCNTL   _at_ 0xe0a0;
unsigned char xdata   RTCCNTH   _at_ 0xe0a1;
unsigned char xdata   RTCMODL   _at_ 0xe0a2;
unsigned char xdata   RTCMODH   _at_ 0xe0a3;

// OPAMP ext Ram ==========================================
unsigned char xdata   OPAMP_CON _at_ 0xe0a4;
unsigned char xdata   OPAMP_SEL _at_ 0xe0a5;

// FLASH_SPI ext Ram ==========================================
unsigned char xdata   CTRLR0    _at_ 0xe0a6;
unsigned char xdata   CTRLR1    _at_ 0xe0a7;
unsigned char xdata   CTRLR2    _at_ 0xe0a8;
unsigned char xdata   MSTATR    _at_ 0xe0a9;
unsigned char xdata   FIFO      _at_ 0xe0aa;
unsigned char xdata   IDR       _at_ 0xe0ab;
unsigned char xdata   ISR       _at_ 0xe0ac;
unsigned char xdata   ICR       _at_ 0xe0ad;

// RC80M ext Ram ==========================================
unsigned char xdata   RC80M_C1  _at_ 0xe0ae;
unsigned char xdata   RC80M_C2  _at_ 0xe0af;
unsigned char xdata   RC80M_C3  _at_ 0xe0b0;
unsigned char xdata   RC80M_CAP _at_ 0xe0b1;
unsigned char xdata   RC80M_RES _at_ 0xe0b2;
unsigned char xdata   RC80M_C   _at_ 0xe0b3;
unsigned char xdata   RC80M_R   _at_ 0xe0b4;
unsigned char xdata   RC_CON    _at_ 0xe0b5;

// external interrupt ext Ram ==========================================
unsigned char xdata   EXT_INT   _at_ 0xe0bf;

unsigned char xdata   WATCH_REG      _at_ 0xe0c0;
unsigned char xdata   PD_CTRL        _at_ 0xe0c1;
unsigned char xdata   COMP_FILTER_1  _at_ 0xe0c2;
unsigned char xdata   COMP_FILTER_2  _at_ 0xe0c3;
unsigned char xdata   COMP_FILTER_3  _at_ 0xe0c4;
unsigned char xdata   COMP_FILTER_4  _at_ 0xe0c5;
unsigned char xdata   COMP_INT_SET   _at_ 0xe0c6;
unsigned char xdata   COMP_INT_REG   _at_ 0xe0c7;
unsigned char xdata   T3CON          _at_ 0xe0c8;
unsigned char xdata   T3PS           _at_ 0xe0c9;
unsigned char xdata   T3CTR_L        _at_ 0xe0ca;
unsigned char xdata   T3CTR_H        _at_ 0xe0cb;
unsigned char xdata   T3RC_L         _at_ 0xe0cc;
unsigned char xdata   T3RC_H         _at_ 0xe0cd;
unsigned char xdata   T4CON          _at_ 0xe0ce;
unsigned char xdata   T4PS           _at_ 0xe0cf;
unsigned char xdata   T4CTR_L        _at_ 0xe0d0;
unsigned char xdata   T4CTR_H        _at_ 0xe0d1;
unsigned char xdata   T4RC_L         _at_ 0xe0d2;
unsigned char xdata   T4RC_H         _at_ 0xe0d3;
unsigned char xdata   P0_FN_L        _at_ 0xe0d4;
unsigned char xdata   P0_FN_H        _at_ 0xe0d5;
unsigned char xdata   P0_DD          _at_ 0xe0d6;
unsigned char xdata   P0_DS          _at_ 0xe0d7;
unsigned char xdata   P0_PE          _at_ 0xe0d8;
unsigned char xdata   P0_PS          _at_ 0xe0d9;
unsigned char xdata   P1_FN_L        _at_ 0xe0da;
unsigned char xdata   P1_FN_H        _at_ 0xe0db;
unsigned char xdata   P1_DD          _at_ 0xe0dc;
unsigned char xdata   P1_DS          _at_ 0xe0dd;
unsigned char xdata   P1_PE          _at_ 0xe0de;
unsigned char xdata   P1_PS          _at_ 0xe0df;
unsigned char xdata   P2_FN_L        _at_ 0xe0e0;
unsigned char xdata   P2_FN_H        _at_ 0xe0e1;
unsigned char xdata   P2_DD          _at_ 0xe0e2;
unsigned char xdata   P2_DS          _at_ 0xe0e3;
unsigned char xdata   P2_PE          _at_ 0xe0e4;
unsigned char xdata   P2_PS          _at_ 0xe0e5;
unsigned char xdata   CLK_DIV_L      _at_ 0xe0e6;
unsigned char xdata   CLK_DIV_H      _at_ 0xe0e7;
unsigned char xdata   CLK_DIV_E      _at_ 0xe0e8;
unsigned char xdata   LVD_INT_EN     _at_ 0xe0e9;
unsigned char xdata   RC80M_OUT_EN   _at_ 0xe0ea;
unsigned char xdata   COMP_INT_EN    _at_ 0xe0eb;
unsigned char xdata   ADC_CLK_CTRL   _at_ 0xe0ec;
unsigned char xdata   MTP_SPI_EN     _at_ 0xe0ed;
unsigned char xdata   TIM01_CLK_DIV_L   _at_ 0xe0ee;
unsigned char xdata   TIM01_CLK_DIV_H   _at_ 0xe0ef;
unsigned char xdata   COMP_INT_SEL   _at_ 0xe0f0;
unsigned char xdata   V18_TUNE       _at_ 0xe0f1;


