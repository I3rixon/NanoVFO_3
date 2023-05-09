//  config for simple superhet like TRX Raisin
//  Single IF=9.216MHz, VFO/BFO are not switched

#ifndef CONFIG_SW_H
#define CONFIG_SW_H

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                  необходимо раскоментировать требуемую моду (только одну!)
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// режим прямого преобразования. при приеме частота VFO формируется на CLK0
// при передаче частота VFO на CLK1 сдвинутая на частоту тона cw
//#define MODE_DC

// режим прямого преобразования с формированием квадратур
// при приеме и передаче SSB частота формируется на выводах CLK0,CLK1 со сдвигом фаз 90град
// при передаче CW частота на CLK2 сдвинутая на частоту тона cw
// Минимальная частота настройки 2MHz (по даташиту 4MHz) может зависеть от экземпляра Si5351
//#define MODE_DC_QUADRATURE

// супергетеродин с одной ПЧ. первый гетеродин всегда выше частоты приема
// боковая полоса выбирается установкой второго гетеродина на нижний/верхний скат фильтра
#define MODE_SUPER

// супергетеродин с двумя ПЧ. первый гетеродин всегда выше частоты приема. 
// нужная боковая выбирается вторым гетеродином
// должны быть определены BFO_LSB или BFO_USB, и SUPER2IF
// генерируются частоты VFO, BFO1, BFO2
//#define MODE_SUPER2

// Частоты 2го гетеродина в детекторе SSB для архитектуры MODE_SUPER
#define BFO_LSB   11057000L
#define BFO_USB   11054000L

// для MODE_SUPER2
//#define SUPER2_IF   45000000L

// для супергетеродина MODE_SUPER надо определить константами что будет 
// на выходе синтезатора в разных режимах работы
// VFO/BFO - первый и второй гетеродины, 
// BFO1, BFO2 - второй и третий гетеродины для режима SUPER2 с двумя ПЧ
// CWTX - cw-сигнал на частоте передачи
// CWIF - cw-сигнал на частоте ПЧ (соответствует частоте принимаемого тона cw)
// 0 - отключенный выход
// задавайте множители в обычной нотации. например 2*VFO, 4*VFO, 2*BFO, 2*CWTX и тп
// CLK3 можно задавать только при двух SI5351 либо при SI5351+SI570

//#define BFO2        500000L
//#define BFO2_LSB
//#define BFO2_USB

#define CLK0_RX_SSB     VFO
#define CLK1_RX_SSB     BFO
#define CLK2_RX_SSB     0
#define CLK3_RX_SSB     0

#define CLK0_RX_CW      VFO
#define CLK1_RX_CW      BFO
#define CLK2_RX_CW      0
#define CLK3_RX_CW      0

#define CLK0_TX_CW      0
#define CLK1_TX_CW      0
#define CLK2_TX_CW      CWTX
#define CLK3_TX_CW      0

#define CLK0_TX_SSB     VFO
#define CLK1_TX_SSB     BFO
#define CLK2_TX_SSB     0
#define CLK3_TX_SSB     0

#endif
