#include "gtest/gtest.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//expected results
string decompressed [10] = {"____*##########*\n__*##############\n__################\n_##################_________*####*\n__##################_____*##########\n__##################___*#############\n___#################*_###############*\n____#################################*\n______###############################\n_______#############################\n________=##########################\n__________########################\n___________*#####################\n____________*##################\n_____________*###############\n_______________#############\n________________##########\n________________=#######*\n_________________######\n__________________####\n__________________###\n___________________#",
                            "______________$$$$$$$\n_____________$$$$$$$$$\n____________$$$$$$$$$$$\n____________$$$$$$$$$$$\n____________$$$$$$$$$$$\n_____________$$$$$$$$$\n_____$$$$$$_____$$$$$$$$$$\n____$$$$$$$$__$$$$$$_____$$$\n___$$$$$$$$$$$$$$$$_________$\n___$$$$$$$$$$$$$$$$______$__$\n___$$$$$$$$$$$$$$$$_____$$$_$\n___$$$$$$$$$$$__________$$$_$_____$$\n____$$$$$$$$$____________$$_$$$$_$$$$\n______$$$__$$__$$$______________$$$$\n___________$$____$_______________$\n____________$$____$______________$\n_____________$$___$$$__________$$\n_______________$$$_$$$$$$_$$$$$\n________________$$____$$_$$$$$\n_______________$$$$$___$$$$$$$$$$\n_______________$$$$$$$$$$$$$$$$$$$$\n_______________$$_$$$$$$$$$$$$$$__$$\n_______________$$__$$$$$$$$$$$___$_$\n______________$$$__$___$$$______$$$$\n______________$$$_$__________$$_$$$$\n______________$$$$$_________$$$$_$_$\n_______________$$$$__________$$$__$$\n_____$$$$_________$________________$\n___$$$___$$______$$$_____________$$\n__$___$$__$$_____$__$$$_____$$__$$\n_$$____$___$_______$$$$$$$$$$$$$\n_$_____$____$_____$$$$$$__$$$$$$$$",
                            "..................$$$$$\n.............$$$$$$....$$$$$$\n..........$$$................$$$\n........$.$$....................$$\n.......$.$$$.....................$$$$\n.....$..$$$$..........................$\n....$..$$$$$..........$$$$$$$.........$$\n...$...$$$$$$$...$$$$$$$$$$$$$$$$$.....$$\n..$....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$....$$\n.$......$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$..$\n.$......$$$$$$$$$$$....$$$$$$$$$$$$$$$$$$$\n$........$$$$$$$$........$$$$$$$........$$\n$.........$$$$$$..........$$$$...........$\n.$.........$$$$$..........$$$...........$\n.$..........$$$$$........$$$$...........$\n.$...........$$$$$$....$$$$$...........$$\n..$...........$$$$$$$$$$$$$$...........$\n..$$............$$$$$$$$$$$$..........$$\n...$$............$$$$$$$$$$..........$$\n....$............$$$$$$$$$...........$\n.....$...........$$$$$$$$...........$\n......$$.........$$$$$$...........$$\n........$$......$$$$$...........$$\n..........$$$.$$$$...........$$$\n.............$$$$$......$$$$$\n..................$$$$$$",
                            "____________#####\n_____________####\n_____________###\n_____________###\n_____________###\n_____________###\n_____________###\n_____________###\n_____________###__##\n_____________###__#__#\n_____________###___#__#\n_____________###___#___#\n_____________###___#____#\n_______##____###__#____#\n______#__#__######____#\n______#___##_____#____###\n_______#____#####____##\n________#___________####\n_________#_________###\n_________##_______###\n________##_________###\n_______##___________###\n______##______##_____##\n_____##_____#_____#___##\n_____##______####_____##\n_____###________________##\n______##_______________###\n_______###____________###\n_________####________###\n___________#########",
                            "____________________$$$$$$$$$$$\n__________________$$$$$$$$$$$$$$\n_________$$$$$$$$$$$$$$$$$$$$$$$\n_____$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n____$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n___$$$_$$_$$$$$$$$$$$$$$$$$$$$$$\n__$$$$$_$$$$$$$$$$$$$$$$$$$$$$\n__$$$_$$_$$$$$$$$$$$$$$$$$_$$$\n__$$$_$$_$$$$$$$$___________$$$$\n_$$$$$_$$$$$$$$$$$___________$$$\n_$$$_$$_$$$$$$$$$$\n_$$$_$$_$$$$$$$$$$\n_$$$_$$_$$$$$$$$$$$\n$_$$$$$$__$$$$$$$$$\n$_$$$$$$___$$$$$$$$\n_$$$$$$$$$__$$$$$$$\n$_$$$$$$$$___$$$$$$\n$$_$$$$$$$$___$$$$$\n$$$_$$$$$$$$__$$$$$$\n_$$$_$$$$$$$$$_$$$$$\n$$$$$ __$$$$$$$$_$$$$\n$$$$$$$ __$$$$$$$$$__$\n$_$_$$$$$__$$$$$$$$$_$$$$\n$$$__$$$$$__$$_$$$$$$$_$$$$\n$$$$$$_$$__$$$$$$$$$$$$$$$\n_$$$$$$$__$$$$$$$$$$$$$$$$\n__$$$$$__$$$$$$$$$$$$$$$$$$\n$__$$$__$$$$$$$$$$$$$$$$$$$$\n$____$$$$$$$$$$$$$$$$$$$$$$$$$\n$____$$$$$$$$$$$$$$$$$$$$$$$$$$\n$__________$$$$$$$$$$$$$$$$$$$$$$\n$____________$$$$$$$$$$$$$$$$$$$$$\n$______________$$$$$$$$$$$$$$$$$$$$\n$_______________$$$$$$$$$$$$$$$$$$\n$_______________$$$$$$$$$$$$$$$$$$\n$____________$$$$$$$$$$$$$$$$$$$\n__________$$$$$$$$$$$$$$$$$$$$\n_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$_$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$__$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$__$$$$$$$$$$$$$____$$$$$$$$$$\n_$$$__$$_$$________$$$$$$$$$$$\n_$$$_$$_____________$$$$$$$$$$\n_$$_$$______________$$$$$$$$$$\n___$$________________$$$$$$$$$$\n_$$$$________________$$$$$$$$$$\n__$$$_________________$$$$$$$$$\n$_____________________$$$$$$$$$\n$____________________$$$$$$$$$$\n$____________________$$$$$$$$$$$\n$____________________$$$$$$$$$__$$$$$\n$___________________$$$$$$$$$$$$$$$$$$\n$____________________$$$$$__$$$$$$$$$$",
                            "__________________ ##\n_________________###*\n______________.*#####\n_____________*######\n___________*#######\n__________*########.\n_________*#########.\n_________*#######*##*\n________*#########*###\n_______*##########*__*##\n_____*###########_____*\n____############\n___*##*#########\n___*_____########\n__________#######\n___________*######\n____________*#####*\n______________*####*\n________________*####\n__________________*##*\n____________________*##\n_____________________*##.\n____________________.#####.\n_________________.##########\n________________.####*__*####",
                            "____////////////////////////////_____\n___///////////////////////////////_______\n__/////////////////////////////////______\n__//////////////////////////////////______\n_////////////$$$$$$$$$$$///////_____\n_///////////$$$$$$$$$$////////_____\n_////////// __$$$____$$$$///_____\n_////////$$$$$$$$$$$$$/////_____\n_////// $$$$$$$$$$$$$////_______\n_///// $$$$$$--$$$$$ _________\n_ // ___$$$$$$$$$$_________\n_ / ______$$$$$____________\n_^$$$b______________e$$$__\n_d$$$$$e__________z$$$$$b_\n_$$$*$$$$$c____.$$$$$*$$$r\n_______^*$$$be$$$*_____^__\n___________$$$$___________\n________.d$$P$$$b_________\n_______d$$P___^$$$b_______\n___.ed$$$________$$$be.___\n_$$$$$$P__________*$$$$$$_\n$$$$$$P____________$$$$$$$",
                            "_____________$$________________________$$$$\n____________$$_____________________________$$\n___________$__________________________________$$\n___________$$___________________________________$$\n__________$$__$$______________________$$__________$$\n________$$__$$___$$$$_________$$$$____$$__________$$$$\n______$$___$$__$$$$__$$_____$$$$__$$_$$_____________$$$\n______$$___$$____$$$$_________$$$$___$$_______________$$\n______$$___$$________________________$$_______________$$\n______$$____$$_______________________$$_____________$$\n________$$__$$____$$$$$$_____________$$___________$$$\n________$$__$$__$$______$$___________$$_________$$\n________$$__$$__$$______$$___________$$_______$$\n__________$$$$____$$$$$$_____________$$$$____$$$$\n__________$$$$_____________________$$__$$____$$$\n___________$$_$$$$$$$$$$$$_____$$$$______$$$$_$$\n_____________$$___$$______$$$$$_______________$$\n_____________$$_____$$$$$$$____________________$$\n_____________$$________________________________$$\n____________$$_________________________________$$\n____________$$_________________________________$$\n____________$$___________________________________$\n____________$$___________________________________$$\n__________$$_________________________$$___________$\n__________$$__________$$___________$$_____________$$\n________$$__$$________$$_________$$_______________$$\n______$$____$$__________$$_______$$_______________$$\n______$$____$$____________$$___$$_________________$$\n____$$______$$_____________$$_$$_______$$_________$$\n____$$______$$________$$____$$$________$$_________$$\n____$$______$$________$$____$$$_______$$__________$$\n____$$______$$________$$_______________$$__________$$\n____$$______$$________$$_______________$$____________$\n_$$$$_______$$________$$_______________$$____________$$\n$___$$______$$________$$$$___________$$$$____________$$\n$___$$______$$________$$__$$_______$$__$$____________$$\n_$$$$$______$$________$$____$$___$$_____$$___________$$\n____$$______$$________$$______$$_______$$___________$$\n____$$______$$________$$_____$$________$$___________$$\n__$$________$$________$$$$$$$$___$$$$$$__$$_________$$\n__$$________$$________$$______$$$______$$$$_________$$\n$$________$$__________$$_________$$$$$$__$$__________$\n$$______$$__________$$$$$$$$$$$$$$$______$$__________$\n$$_$$_$$$__________$$_____________$$$$$$$__$$_________$\n_$$$$$$$___________$$______________________$$________$$\n_____$$__$$__$$__$$_$______________________$$__________$$\n______$$$$__$___$__$$______________________$$____________$\n_______$$___$___$__$________________________$$_$__$$__$$__$\n_________$$$$$$$$$$__________________________$$_$_$$$$$$$$",
                            "_____$$$$__________$$$$$\n___$$$$$$$$______$$$$$$$$$\n__$$$$$$$$$$____$$$$$$$$$$$\n_$$$$$$$$$$$$__$$$$$$$$$$$$$\n_$$$$$$$$$$$$$_$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_$$$$\n$$$$$$$$$$$$$$$$$_____$$$$$$$______$\n$$$$$$$$$$$$$$$$________$$$$________$\n_$$$$$$$$$$$$$$__________$$__________$\n_$$$$$$$$$$$$$___________$___________$\n_$$$$$$$$$$$$$_______________________$\n__$$$$$$$$$$$$_______________________$\n___$$$$$$$$$$$_______________________$\n____$$$$$$$$$$_______________________$\n_____$$$$$$$$$_______________________$\n______$$$$__$$$__$$$$$_______________$\n_______$______$_$_____$_____________$\n______$_______$$______$_____________$\n______$________________$___________$\n______$________________$__________$\n_______$_______________$_________$\n_______$______________$_________$\n________$_____________$________$\n_________$___________$$______$\n__________$_________$__$____$\n___________$_______$_____$$\n____________$$___$$\n______________$$$\n_______________$",
                            "_$_$$_______$__$_____$$____$________________\n____________$___$$$____$___$__$$_____$_________________\n____________$_____$$$_$____$_$$______$______$$_________\n_____________$_______$$_____$________$__$$$$_$_________\n_____________$_______________________$$$_____$_________\n_____________$______________________________$__________\n___$$$$$$_____$_____________________________$__________\n____$______$$$_____________________________$___________\n____$$_____________________________________$$$_________\n_____$________________________________________$$$$_____\n______$________________________________________ _$$_____\n_______$_______________________________________$_______\n_______$$____________________$_______________$$________\n_______$_____________$$$$$$$$$_______________$_________\n______$_____________$$$$$$$$$$$_______$_______$$_______\n____$$____________$$$$$$$$$$$$$$________________$$_____\n___$_____________$$$$$$____$$$$$$___$___$_________$$___\n__$_____________$$$$$______$$$$$$____$__$$__________$__\n$$_____________$$$$__$______$$$$$$$__$$__$________$$___\n$_____________$$$$__$$______$$$$$$$__$$$_$$___$$$$_____\n______________$$$__$_$$_____$$$$$$$$__$$$_$$__$________\n_____________$$$___$$$_____$$$$$$$$$$_$$$$$$$__$_______\n_____________$$____$$$____$$$$$$$$$_$$$$$$$$$___$______\n$$$__________$_____$$$$_$$$$$$________$__$$$$$___$_____\n___$$_______$$$____$$_$$$$$$$_____________$$$$$__$$____\n____$_______$$$$___$_$$$$$__$________$____$$$$$$$$$$$$$\n___$___$____$$$$$__$$$$$$__$______$$$________$__$$$$$$$\n___$___$____$$$$$$$$$$$___$_____$$_________$_$$_$$$$$$$\n__$____$____$$$$$$$$$$_________$$______$$$$$_$$__$$$$$$\n_$_____$____$$$$$$$$$__________$______$_____$$$__$__$$$\n_$____$$____$$$$$$$$$_______________________$$$__$_____\n$______$____$$$$$$$$$$$$$____________________$$$_$_____\n___$$$$_____$$$$$$_______$______________$$_$$$_$$______\n______$__$__$$$$$$_$$$$$_____________________$$_$$_____\n______$_$$__$$$$$_$$_$$_$_____________________$$_$$____\n______$_$_$_$$$$$_$_$$$$$_________________$$$____$$____\n______$_$_$_$$$$$_$_$$$$_____________________$____$____\n______$$$_$$$$$$$_$$$$$$_______$_____$$$________$__$___\n______$$$__$_$$$$__$$$$______$_____$$_________$$$_$$$__\n______$_$___$_$_$___________$_____$___$$$_____$$__$$$$$\n________$__$$____$______________$$__$$__$_____$$$_$$$$$\n__________$____$_$$____________$$__$___$______$_$$_$$$$\n_________$$_____$_$_$_________$$_$$__$$_______$__$$$_$$\n_________$_______$_$__________$_$___$________$$__$$$___\n_________________$$$_________$_$__$$_________$$__$$$$__\n_________________$_$$_$_____$_$_$$___________$$_$$$$$__\n__________________$$$$$_____$$$$_____$______$$$$$$$$$__\n___________________$$$____________$$$______$$$$$$$$$$$_\n____________________$$$__$________________$$$$$$$$$$$$$\n_____________________$$$_$_______________$$$$$$$$$$$$$$\n______________________$_$$______________$$$$$$$$$$$$$$$\n________________________$$$____________$$$$$$$$$$$$$$$$\n__________________________$$$$________$$$$$$$$$$$$$$$$$\n_____________________________$$$$__$$$$$$$"};

string compressed[10] = {"4_1*10#1*1>2_1*14#1>2_16#1>1_18#9_1*4#1*1>2_18#5_1*10#1>2_18#3_1*13#1>3_17#1*1_15#1*1>4_33#1*1>6_31#1>7_29#1>8_1=26#1>10_24#1>11_1*21#1>12_1*18#1>13_1*15#1>15_13#1>16_10#1>16_1=7#1*1>17_6#1>18_4#1>18_3#1>19_1#",
                        "14_7$1>13_9$1>12_11$1>12_11$1>12_11$1>13_9$1>5_6$5_10$1>4_8$2_6$5_3$1>3_16$9_1$1>3_16$6_1$2_1$1>3_16$5_3$1_1$1>3_11$10_3$1_1$5_2$1>4_9$12_2$1_4$1_4$1>6_3$2_2$2_3$14_4$1>11_2$4_1$15_1$1>12_2$4_1$14_1$1>13_2$3_3$10_2$1>15_3$1_6$1_5$1>16_2$4_2$1_5$1>15_5$3_10$1>15_20$1>15_2$1_14$2_2$1>15_2$2_11$3_1$1_1$1>14_3$2_1$3_3$6_4$1>14_3$1_1$10_2$1_4$1>14_5$9_4$1_1$1_1$1>15_4$10_3$2_2$1>5_4$9_1$16_1$1>3_3$3_2$6_3$13_2$1>2_1$3_2$2_2$5_1$2_3$5_2$2_2$1>1_2$4_1$3_1$7_13$1>1_1$5_1$4_1$5_6$2_8$",
                        "18.5$1>13.6$4.6$1>10.3$16.3$1>8.1$1.2$20.2$1>7.1$1.3$21.4$1>5.1$2.4$26.1$1>4.1$2.5$10.7$9.2$1>3.1$3.7$3.17$5.2$1>2.1$4.29$4.2$1>1.1$6.31$2.1$1>1.1$6.11$4.19$1>1$8.8$8.7$8.2$1>1$9.6$10.4$11.1$1>1.1$9.5$10.3$11.1$1>1.1$10.5$8.4$11.1$1>1.1$11.6$4.5$11.2$1>2.1$11.14$11.1$1>2.2$12.12$10.2$1>3.2$12.10$10.2$1>4.1$12.9$11.1$1>5.1$11.8$11.1$1>6.2$9.6$11.2$1>8.2$6.5$11.2$1>10.3$1.4$11.3$1>13.5$6.5$1>18.6$",
                        "12_5#1>13_4#1>13_3#1>13_3#1>13_3#1>13_3#1>13_3#1>13_3#1>13_3#2_2#1>13_3#2_1#2_1#1>13_3#3_1#2_1#1>13_3#3_1#3_1#1>13_3#3_1#4_1#1>7_2#4_3#2_1#4_1#1>6_1#2_1#2_6#4_1#1>6_1#3_2#5_1#4_3#1>7_1#4_5#4_2#1>8_1#11_4#1>9_1#9_3#1>9_2#7_3#1>8_2#9_3#1>7_2#11_3#1>6_2#6_2#5_2#1>5_2#5_1#5_1#3_2#1>5_2#6_4#5_2#1>5_3#16_2#1>6_2#15_3#1>7_3#12_3#1>9_4#8_3#1>11_9#",
                        "20_11$1>18_14$1>9_23$1>5_28$1>4_29$1>3_3$1_2$1_22$1>2_5$1_22$1>2_3$1_2$1_17$1_3$1>2_3$1_2$1_8$11_4$1>1_5$1_11$11_3$1>1_3$1_2$1_10$1>1_3$1_2$1_10$1>1_3$1_2$1_11$1>1$1_6$2_9$1>1$1_6$3_8$1>1_9$2_7$1>1$1_8$3_6$1>2$1_8$3_5$1>3$1_8$2_6$1>1_3$1_9$1_5$1>5$2_8$1_4$1>7$2_9$2_1$1>1$1_1$1_5$2_9$1_4$1>3$2_5$2_2$1_7$1_4$1>6$1_2$2_15$1>1_7$2_16$1>2_5$2_18$1>1$2_3$2_20$1>1$4_25$1>1$4_26$1>1$10_22$1>1$12_21$1>1$14_20$1>1$15_18$1>1$15_18$1>1$12_19$1>10_20$1>1_29$1>1$1_28$1>1$2_27$1>1$2_13$4_10$1>1_3$2_2$1_2$8_11$1>1_3$1_2$13_10$1>1_2$1_2$14_10$1>3_2$16_10$1>1_4$16_10$1>2_3$17_9$1>1$21_9$1>1$20_10$1>1$20_11$1>1$20_9$2_5$1>1$19_18$1>1$20_5$2_10$",
                        "18_2#1>17_3#1*1>14_1.1*5#1>13_1*6#1>11_1*7#1>10_1*8#1.1>9_1*9#1.1>9_1*7#1*2#1*1>8_1*9#1*3#1>7_1*10#1*2_1*2#1>5_1*11#5_1*1>4_12#1>3_1*2#1*9#1>3_1*5_8#1>10_7#1>11_1*6#1>12_1*5#1*1>14_1*4#1*1>16_1*4#1>18_1*2#1*1>20_1*2#1>21_1*2#1.1>20_1.5#1.1>17_1.10#1>16_1.4#1*2_1*4#",
                        "4_28/5_1>3_31/7_1>2_33/6_1>2_34/6_1>1_12/11$7/5_1>1_11/10$8/5_1>1_10/2_3$4_4$3/5_1>1_8/13$5/5_1>1_6/13$4/7_1>1_5/6$2-5$9_1>1_2/3_10$9_1>1_1/6_5$12_1>1_1^3$1b14_1e3$2_1>1_1d5$1e10_1z5$1b1_1>1_3$1*5$1c4_1.5$1*3$1r1>7_1^1*3$1b1e3$1*5_1^2_1>11_4$11_1>8_1.1d2$1P3$1b9_1>7_1d2$1P3_1^3$1b7_1>3_1.1e1d3$8_3$1b1e1.3_1>1_6$1P10_1*6$1_1>6$1P12_7$",
                        "13_2$24_4$1>12_2$29_2$1>11_1$34_2$1>11_2$35_2$1>10_2$2_2$22_2$10_2$1>8_2$2_2$3_4$9_4$4_2$10_4$1>6_2$3_2$2_4$2_2$5_4$2_2$1_2$13_3$1>6_2$3_2$4_4$9_4$3_2$15_2$1>6_2$3_2$24_2$15_2$1>6_2$4_2$23_2$13_2$1>8_2$2_2$4_6$13_2$11_3$1>8_2$2_2$2_2$6_2$11_2$9_2$1>8_2$2_2$2_2$6_2$11_2$7_2$1>10_4$4_6$13_4$4_4$1>10_4$21_2$2_2$4_3$1>11_2$1_12$5_4$6_4$1_2$1>13_2$3_2$6_5$15_2$1>13_2$5_7$20_2$1>13_2$32_2$1>12_2$33_2$1>12_2$33_2$1>12_2$35_1$1>12_2$35_2$1>10_2$25_2$11_1$1>10_2$10_2$11_2$13_2$1>8_2$2_2$8_2$9_2$15_2$1>6_2$4_2$10_2$7_2$15_2$1>6_2$4_2$12_2$3_2$17_2$1>4_2$6_2$13_2$1_2$7_2$9_2$1>4_2$6_2$8_2$4_3$8_2$9_2$1>4_2$6_2$8_2$4_3$7_2$10_2$1>4_2$6_2$8_2$15_2$10_2$1>4_2$6_2$8_2$15_2$12_1$1>1_4$7_2$8_2$15_2$12_2$1>1$3_2$6_2$8_4$11_4$12_2$1>1$3_2$6_2$8_2$2_2$7_2$2_2$12_2$1>1_5$6_2$8_2$4_2$3_2$5_2$11_2$1>4_2$6_2$8_2$6_2$7_2$11_2$1>4_2$6_2$8_2$5_2$8_2$11_2$1>2_2$8_2$8_8$3_6$2_2$9_2$1>2_2$8_2$8_2$6_3$6_4$9_2$1>2$8_2$10_2$9_6$2_2$10_1$1>2$6_2$10_15$6_2$10_1$1>2$1_2$1_3$10_2$13_7$2_2$9_1$1>1_7$11_2$22_2$8_2$1>5_2$2_2$2_2$2_2$1_1$22_2$10_2$1>6_4$2_1$3_1$2_2$22_2$12_1$1>7_2$3_1$3_1$2_1$24_2$1_1$2_2$2_2$2_1$1>9_10$26_2$1_1$1_8$",
                        "5_4$10_5$1>3_8$6_9$1>2_10$4_11$1>1_12$2_13$1>1_13$1_13$1>28$1>29$1>29$1_4$1>17$5_7$6_1$1>16$8_4$8_1$1>1_14$10_2$10_1$1>1_13$11_1$11_1$1>1_13$23_1$1>2_12$23_1$1>3_11$23_1$1>4_10$23_1$1>5_9$23_1$1>6_4$2_3$2_5$15_1$1>7_1$6_1$1_1$5_1$13_1$1>6_1$7_2$6_1$13_1$1>6_1$16_1$11_1$1>6_1$16_1$10_1$1>7_1$15_1$9_1$1>7_1$14_1$9_1$1>8_1$13_1$8_1$1>9_1$11_2$6_1$1>10_1$9_1$2_1$4_1$1>11_1$7_1$5_2$1>12_2$3_2$1>14_3$1>15_1$",
                        "1_1$1_2$7_1$2_1$5_2$4_1$16_1>12_1$3_3$4_1$3_1$2_2$5_1$17_1>12_1$5_3$1_1$4_1$1_2$6_1$6_2$9_1>13_1$7_2$5_1$8_1$2_4$1_1$9_1>13_1$23_3$5_1$9_1>13_1$30_1$10_1>3_6$5_1$29_1$10_1>4_1$6_3$29_1$11_1>4_2$37_3$9_1>5_1$40_4$5_1>6_1$40_1_2$5_1>7_1$39_1$7_1>7_2$20_1$15_2$8_1>7_1$13_9$15_1$9_1>6_1$13_11$7_1$7_2$7_1>4_2$12_14$16_2$5_1>3_1$13_6$4_6$3_1$3_1$9_2$3_1>2_1$13_5$6_6$4_1$2_2$10_1$2_1>2$13_4$2_1$6_7$2_2$2_1$8_2$3_1>1$13_4$2_2$6_7$2_3$1_2$3_4$5_1>14_3$2_1$1_2$5_8$2_3$1_2$2_1$8_1>13_3$3_3$5_10$1_7$2_1$7_1>13_2$4_3$4_9$1_9$3_1$6_1>3$10_1$5_4$1_6$8_1$2_5$3_1$5_1>3_2$7_3$4_2$1_7$13_5$2_2$4_1>4_1$7_4$3_1$1_5$2_1$8_1$4_13$1>3_1$3_1$4_5$2_6$2_1$6_3$8_1$2_7$1>3_1$3_1$4_11$3_1$5_2$9_1$1_2$1_7$1>2_1$4_1$4_10$9_2$6_5$1_2$2_6$1>1_1$5_1$4_9$10_1$6_1$5_3$2_1$2_3$1>1_1$4_2$4_9$23_3$2_1$5_1>1$6_1$4_13$20_3$1_1$5_1>3_4$5_6$7_1$14_2$1_3$1_2$6_1>6_1$2_1$2_6$1_5$21_2$1_2$5_1>6_1$1_2$2_5$1_2$1_2$1_1$21_2$1_2$4_1>6_1$1_1$1_1$1_5$1_1$1_5$17_3$4_2$4_1>6_1$1_1$1_1$1_5$1_1$1_4$21_1$4_1$4_1>6_3$1_7$1_6$7_1$5_3$8_1$2_1$3_1>6_3$2_1$1_4$2_4$6_1$5_2$9_3$1_3$2_1>6_1$1_1$3_1$1_1$1_1$11_1$5_1$3_3$5_2$2_5$1>8_1$2_2$4_1$14_2$2_2$2_1$5_3$1_5$1>10_1$4_1$1_2$12_2$2_1$3_1$6_1$1_2$1_4$1>9_2$5_1$1_1$1_1$9_2$1_2$2_2$7_1$2_3$1_2$1>9_1$7_1$1_1$10_1$1_1$3_1$8_2$2_3$3_1>17_3$9_1$1_1$2_2$9_2$2_4$2_1>17_1$1_2$1_1$5_1$1_1$1_2$11_2$1_5$2_1>18_5$5_4$5_1$6_9$2_1>19_3$12_3$6_11$1_1>20_3$2_1$16_13$1>21_3$1_1$15_14$1>22_1$1_2$14_15$1>24_3$12_16$1>26_4$8_17$1>29_4$2_7$"};

string artCharacters [10] = { "____*##########*>__*##############>__################>_##################_________*####*>__##################_____*##########>__##################___*#############>___#################*_###############*>____#################################*>______###############################>_______#############################>________=##########################>__________########################>___________*#####################>____________*##################>_____________*###############>_______________#############>________________##########>________________=#######*>_________________######>__________________####>__________________###>___________________#",
                            "______________$$$$$$$>_____________$$$$$$$$$>____________$$$$$$$$$$$>____________$$$$$$$$$$$>____________$$$$$$$$$$$>_____________$$$$$$$$$>_____$$$$$$_____$$$$$$$$$$>____$$$$$$$$__$$$$$$_____$$$>___$$$$$$$$$$$$$$$$_________$>___$$$$$$$$$$$$$$$$______$__$>___$$$$$$$$$$$$$$$$_____$$$_$>___$$$$$$$$$$$__________$$$_$_____$$>____$$$$$$$$$____________$$_$$$$_$$$$>______$$$__$$__$$$______________$$$$>___________$$____$_______________$>____________$$____$______________$>_____________$$___$$$__________$$>_______________$$$_$$$$$$_$$$$$>________________$$____$$_$$$$$>_______________$$$$$___$$$$$$$$$$>_______________$$$$$$$$$$$$$$$$$$$$>_______________$$_$$$$$$$$$$$$$$__$$>_______________$$__$$$$$$$$$$$___$_$>______________$$$__$___$$$______$$$$>______________$$$_$__________$$_$$$$>______________$$$$$_________$$$$_$_$>_______________$$$$__________$$$__$$>_____$$$$_________$________________$>___$$$___$$______$$$_____________$$>__$___$$__$$_____$__$$$_____$$__$$>_$$____$___$_______$$$$$$$$$$$$$>_$_____$____$_____$$$$$$__$$$$$$$$",
                            "..................$$$$$>.............$$$$$$....$$$$$$>..........$$$................$$$>........$.$$....................$$>.......$.$$$.....................$$$$>.....$..$$$$..........................$>....$..$$$$$..........$$$$$$$.........$$>...$...$$$$$$$...$$$$$$$$$$$$$$$$$.....$$>..$....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$....$$>.$......$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$..$>.$......$$$$$$$$$$$....$$$$$$$$$$$$$$$$$$$>$........$$$$$$$$........$$$$$$$........$$>$.........$$$$$$..........$$$$...........$>.$.........$$$$$..........$$$...........$>.$..........$$$$$........$$$$...........$>.$...........$$$$$$....$$$$$...........$$>..$...........$$$$$$$$$$$$$$...........$>..$$............$$$$$$$$$$$$..........$$>...$$............$$$$$$$$$$..........$$>....$............$$$$$$$$$...........$>.....$...........$$$$$$$$...........$>......$$.........$$$$$$...........$$>........$$......$$$$$...........$$>..........$$$.$$$$...........$$$>.............$$$$$......$$$$$>..................$$$$$$",
                            "____________#####>_____________####>_____________###>_____________###>_____________###>_____________###>_____________###>_____________###>_____________###__##>_____________###__#__#>_____________###___#__#>_____________###___#___#>_____________###___#____#>_______##____###__#____#>______#__#__######____#>______#___##_____#____###>_______#____#####____##>________#___________####>_________#_________###>_________##_______###>________##_________###>_______##___________###>______##______##_____##>_____##_____#_____#___##>_____##______####_____##>_____###________________##>______##_______________###>_______###____________###>_________####________###>___________#########",
                            "____________________$$$$$$$$$$$>__________________$$$$$$$$$$$$$$>_________$$$$$$$$$$$$$$$$$$$$$$$>_____$$$$$$$$$$$$$$$$$$$$$$$$$$$$>____$$$$$$$$$$$$$$$$$$$$$$$$$$$$$>___$$$_$$_$$$$$$$$$$$$$$$$$$$$$$>__$$$$$_$$$$$$$$$$$$$$$$$$$$$$>__$$$_$$_$$$$$$$$$$$$$$$$$_$$$>__$$$_$$_$$$$$$$$___________$$$$>_$$$$$_$$$$$$$$$$$___________$$$>_$$$_$$_$$$$$$$$$$>_$$$_$$_$$$$$$$$$$>_$$$_$$_$$$$$$$$$$$>$_$$$$$$__$$$$$$$$$>$_$$$$$$___$$$$$$$$>_$$$$$$$$$__$$$$$$$>$_$$$$$$$$___$$$$$$>$$_$$$$$$$$___$$$$$>$$$_$$$$$$$$__$$$$$$>_$$$_$$$$$$$$$_$$$$$>$$$$$__$$$$$$$$_$$$$>$$$$$$$__$$$$$$$$$__$>$_$_$$$$$__$$$$$$$$$_$$$$>$$$__$$$$$__$$_$$$$$$$_$$$$>$$$$$$_$$__$$$$$$$$$$$$$$$>_$$$$$$$__$$$$$$$$$$$$$$$$>__$$$$$__$$$$$$$$$$$$$$$$$$>$__$$$__$$$$$$$$$$$$$$$$$$$$>$____$$$$$$$$$$$$$$$$$$$$$$$$$>$____$$$$$$$$$$$$$$$$$$$$$$$$$$>$__________$$$$$$$$$$$$$$$$$$$$$$>$____________$$$$$$$$$$$$$$$$$$$$$>$______________$$$$$$$$$$$$$$$$$$$$>$_______________$$$$$$$$$$$$$$$$$$>$_______________$$$$$$$$$$$$$$$$$$>$____________$$$$$$$$$$$$$$$$$$$>__________$$$$$$$$$$$$$$$$$$$$>_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$>$_$$$$$$$$$$$$$$$$$$$$$$$$$$$$>$__$$$$$$$$$$$$$$$$$$$$$$$$$$$>$__$$$$$$$$$$$$$____$$$$$$$$$$>_$$$__$$_$$________$$$$$$$$$$$>_$$$_$$_____________$$$$$$$$$$>_$$_$$______________$$$$$$$$$$>___$$________________$$$$$$$$$$>_$$$$________________$$$$$$$$$$>__$$$_________________$$$$$$$$$>$_____________________$$$$$$$$$>$____________________$$$$$$$$$$>$____________________$$$$$$$$$$$>$____________________$$$$$$$$$__$$$$$>$___________________$$$$$$$$$$$$$$$$$$>$____________________$$$$$__$$$$$$$$$$",
                            "__________________##>_________________###*>______________.*#####>_____________*######>___________*#######>__________*########.>_________*#########.>_________*#######*##*>________*#########*###>_______*##########*__*##>_____*###########_____*>____############>___*##*#########>___*_____########>__________#######>___________*######>____________*#####*>______________*####*>________________*####>__________________*##*>____________________*##>_____________________*##.>____________________.#####.>_________________.##########>________________.####*__*####",
                            "____////////////////////////////_____>___///////////////////////////////_______>__/////////////////////////////////______>__//////////////////////////////////______>_////////////$$$$$$$$$$$///////_____>_///////////$$$$$$$$$$////////_____>_//////////__$$$____$$$$///_____>_////////$$$$$$$$$$$$$/////_____>_//////$$$$$$$$$$$$$////_______>_/////$$$$$$--$$$$$_________>_//___$$$$$$$$$$_________>_/______$$$$$____________>_^$$$b______________e$$$__>_d$$$$$e__________z$$$$$b_>_$$$*$$$$$c____.$$$$$*$$$r>_______^*$$$be$$$*_____^__>___________$$$$___________>________.d$$P$$$b_________>_______d$$P___^$$$b_______>___.ed$$$________$$$be.___>_$$$$$$P__________*$$$$$$_>$$$$$$P____________$$$$$$$",
                            "_____________$$________________________$$$$>____________$$_____________________________$$>___________$__________________________________$$>___________$$___________________________________$$>__________$$__$$______________________$$__________$$>________$$__$$___$$$$_________$$$$____$$__________$$$$>______$$___$$__$$$$__$$_____$$$$__$$_$$_____________$$$>______$$___$$____$$$$_________$$$$___$$_______________$$>______$$___$$________________________$$_______________$$>______$$____$$_______________________$$_____________$$>________$$__$$____$$$$$$_____________$$___________$$$>________$$__$$__$$______$$___________$$_________$$>________$$__$$__$$______$$___________$$_______$$>__________$$$$____$$$$$$_____________$$$$____$$$$>__________$$$$_____________________$$__$$____$$$>___________$$_$$$$$$$$$$$$_____$$$$______$$$$_$$>_____________$$___$$______$$$$$_______________$$>_____________$$_____$$$$$$$____________________$$>_____________$$________________________________$$>____________$$_________________________________$$>____________$$_________________________________$$>____________$$___________________________________$>____________$$___________________________________$$>__________$$_________________________$$___________$>__________$$__________$$___________$$_____________$$>________$$__$$________$$_________$$_______________$$>______$$____$$__________$$_______$$_______________$$>______$$____$$____________$$___$$_________________$$>____$$______$$_____________$$_$$_______$$_________$$>____$$______$$________$$____$$$________$$_________$$>____$$______$$________$$____$$$_______$$__________$$>____$$______$$________$$_______________$$__________$$>____$$______$$________$$_______________$$____________$>_$$$$_______$$________$$_______________$$____________$$>$___$$______$$________$$$$___________$$$$____________$$>$___$$______$$________$$__$$_______$$__$$____________$$>_$$$$$______$$________$$____$$___$$_____$$___________$$>____$$______$$________$$______$$_______$$___________$$>____$$______$$________$$_____$$________$$___________$$>__$$________$$________$$$$$$$$___$$$$$$__$$_________$$>__$$________$$________$$______$$$______$$$$_________$$>$$________$$__________$$_________$$$$$$__$$__________$>$$______$$__________$$$$$$$$$$$$$$$______$$__________$>$$_$$_$$$__________$$_____________$$$$$$$__$$_________$>_$$$$$$$___________$$______________________$$________$$>_____$$__$$__$$__$$_$______________________$$__________$$>______$$$$__$___$__$$______________________$$____________$>_______$$___$___$__$________________________$$_$__$$__$$__$>_________$$$$$$$$$$__________________________$$_$_$$$$$$$$",
                            "_____$$$$__________$$$$$>___$$$$$$$$______$$$$$$$$$>__$$$$$$$$$$____$$$$$$$$$$$>_$$$$$$$$$$$$__$$$$$$$$$$$$$>_$$$$$$$$$$$$$_$$$$$$$$$$$$$>$$$$$$$$$$$$$$$$$$$$$$$$$$$$>$$$$$$$$$$$$$$$$$$$$$$$$$$$$$>$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_$$$$>$$$$$$$$$$$$$$$$$_____$$$$$$$______$>$$$$$$$$$$$$$$$$________$$$$________$>_$$$$$$$$$$$$$$__________$$__________$>_$$$$$$$$$$$$$___________$___________$>_$$$$$$$$$$$$$_______________________$>__$$$$$$$$$$$$_______________________$>___$$$$$$$$$$$_______________________$>____$$$$$$$$$$_______________________$>_____$$$$$$$$$_______________________$>______$$$$__$$$__$$$$$_______________$>_______$______$_$_____$_____________$>______$_______$$______$_____________$>______$________________$___________$>______$________________$__________$>_______$_______________$_________$>_______$______________$_________$>________$_____________$________$>_________$___________$$______$>__________$_________$__$____$>___________$_______$_____$$>____________$$___$$>______________$$$>_______________$",
                            "_$_$$_______$__$_____$$____$________________>____________$___$$$____$___$__$$_____$_________________>____________$_____$$$_$____$_$$______$______$$_________>_____________$_______$$_____$________$__$$$$_$_________>_____________$_______________________$$$_____$_________>_____________$______________________________$__________>___$$$$$$_____$_____________________________$__________>____$______$$$_____________________________$___________>____$$_____________________________________$$$_________>_____$________________________________________$$$$_____>______$_________________________________________$$_____>_______$_______________________________________$_______>_______$$____________________$_______________$$________>_______$_____________$$$$$$$$$_______________$_________>______$_____________$$$$$$$$$$$_______$_______$$_______>____$$____________$$$$$$$$$$$$$$________________$$_____>___$_____________$$$$$$____$$$$$$___$___$_________$$___>__$_____________$$$$$______$$$$$$____$__$$__________$__>$$_____________$$$$__$______$$$$$$$__$$__$________$$___>$_____________$$$$__$$______$$$$$$$__$$$_$$___$$$$_____>______________$$$__$_$$_____$$$$$$$$__$$$_$$__$________>_____________$$$___$$$_____$$$$$$$$$$_$$$$$$$__$_______>_____________$$____$$$____$$$$$$$$$_$$$$$$$$$___$______>$$$__________$_____$$$$_$$$$$$________$__$$$$$___$_____>___$$_______$$$____$$_$$$$$$$_____________$$$$$__$$____>____$_______$$$$___$_$$$$$__$________$____$$$$$$$$$$$$$>___$___$____$$$$$__$$$$$$__$______$$$________$__$$$$$$$>___$___$____$$$$$$$$$$$___$_____$$_________$_$$_$$$$$$$>__$____$____$$$$$$$$$$_________$$______$$$$$_$$__$$$$$$>_$_____$____$$$$$$$$$__________$______$_____$$$__$__$$$>_$____$$____$$$$$$$$$_______________________$$$__$_____>$______$____$$$$$$$$$$$$$____________________$$$_$_____>___$$$$_____$$$$$$_______$______________$$_$$$_$$______>______$__$__$$$$$$_$$$$$_____________________$$_$$_____>______$_$$__$$$$$_$$_$$_$_____________________$$_$$____>______$_$_$_$$$$$_$_$$$$$_________________$$$____$$____>______$_$_$_$$$$$_$_$$$$_____________________$____$____>______$$$_$$$$$$$_$$$$$$_______$_____$$$________$__$___>______$$$__$_$$$$__$$$$______$_____$$_________$$$_$$$__>______$_$___$_$_$___________$_____$___$$$_____$$__$$$$$>________$__$$____$______________$$__$$__$_____$$$_$$$$$>__________$____$_$$____________$$__$___$______$_$$_$$$$>_________$$_____$_$_$_________$$_$$__$$_______$__$$$_$$>_________$_______$_$__________$_$___$________$$__$$$___>_________________$$$_________$_$__$$_________$$__$$$$__>_________________$_$$_$_____$_$_$$___________$$_$$$$$__>__________________$$$$$_____$$$$_____$______$$$$$$$$$__>___________________$$$____________$$$______$$$$$$$$$$$_>____________________$$$__$________________$$$$$$$$$$$$$>_____________________$$$_$_______________$$$$$$$$$$$$$$>______________________$_$$______________$$$$$$$$$$$$$$$>________________________$$$____________$$$$$$$$$$$$$$$$>__________________________$$$$________$$$$$$$$$$$$$$$$$>_____________________________$$$$__$$$$$$$"};


int compressTest = 0; //number of compressTest
int decompressTest = 0; //number of compressTest
int artTest = 0; //vector with characters


class AsciiArt
{
public:
    string comp;
    string decomp;
    vector <string> art;

    AsciiArt(){}

    void fill(FILE * archivo)
    {
        string comp = "";
        char linea[240];
        int j = 0;

        char caracter = '1'; //caracter actual

        while(!feof(archivo))
        {
            //leemos una linea
            fgets(linea, 240, archivo);
            //checamos la oracion
            for(int i = 0; i < (int)strlen(linea); i++)
            {
                //cout<<"caracter: "<<linea[i]<<endl;
                if((int)linea[i] == 10) //si es cambio de linea
                {
                    art.push_back(">");
                }
                else //pasamos el caracter
                {
                    stringstream ss;
                    ss << linea[i]; //metemos el caracter
                    string temp;
                    ss >> temp; //metemos a string temporal
                    art.push_back(temp); //aniadimos al 
                }
            }
            j++;
        }
    }   

    void compress()
    {
        int i  = 0;
        int j = 0;

        int band[2] = {10, 10};
        int cont = 0;
        string caracter = "";

        caracter = art[0]; //primer caracter
        cont = 1;
        
        for(int i = 1; i < art.size(); i++)
        {
            if(caracter == art[i]) //mismo caracter
            {
                cont++;
            }
            else if ((int)caracter[0] == 0) //no se debe hacer nada
            {
                caracter = art[i];
            }
            else
            {
                comp = comp + to_string(cont); //pasamos el numero de veces que aparecio el caracter
                cont = 1; //reiniciamos el contador a 1
                comp = comp + caracter; //pasamos el caracter que teniamos
                caracter = art[i]; //pasamos al nuevo caracter
            }

            if(i == art.size()-1)
            {
                comp = comp + to_string(cont); //pasamos el numero de veces que aparecio el caracter
                cont = 1; //reiniciamos el contador a 1
                comp = comp + caracter; //pasamos el caracter que teniamos
                caracter = art[i]; //pasamos al nuevo caracter
            }
        }

        //cout<<"comp: "<<endl<<comp<<endl;
    }

    void decompress()
    {
        string caracter;
        string num = "";
        //cout<<comp[comp.length()-1]<<endl;

        for(int i = 0; i < comp.length(); i++)
        {
            caracter = comp[i]; //caracter que vamos a trabajar este ciclos

            if((int)caracter[0] > 47 && (int)caracter[0] < 58) //es un numero
            {
                num = num + caracter[0];
            }
            else //encontramos un signo
            {
                int temp = stoi(num); //veces que se repetira la insercion del signo

                for(int j = 0; j < temp; j++ ) //insercion del signo
                {
                    if(caracter[0] == '>') //cambio de linea
                    {
                        decomp = decomp + "\n";
                    }
                    else    //cualquier signo
                    {
                        decomp = decomp + caracter[0];
                    }
                }
                num = "";
            }
        }
        //cout<<"decomp: "<<endl<<decomp<<endl;
    }
};

class Mytest : public testing::TestWithParam<const char*>
{
public:
    AsciiArt art;
    FILE * archivo = NULL;
  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
    fclose(archivo);
  }
};

INSTANTIATE_TEST_CASE_P(InstantiationName,
                        Mytest,
                        ::testing::Values("./art/ascii1.art", "./art/ascii2.art", "./art/ascii3.art", "./art/ascii4.art", "./art/ascii5.art"
                        , "./art/ascii6.art", "./art/ascii7.art", "./art/ascii8.art", "./art/ascii9.art", "./art/ascii10.art"));

TEST_P(Mytest, fileTest)
{
    archivo = fopen(GetParam(), "r");
    art.fill(archivo);

    stringstream ss;
    ss << artCharacters[artTest];
    string temp;
    ss >> temp;

    bool equal = true;
    if(temp.length() == art.decomp.length())
    {
        for(int i = 0; i < temp.length(); i++)
        {
            if( temp[i] != art.decomp[i])
            {
                equal = false;
            }
        }
    }

    artTest++;
    ASSERT_TRUE(equal);
}

TEST_P(Mytest, compTest)
{
    archivo = fopen(GetParam(), "r");
    art.fill(archivo);

    art.compress();

    stringstream ss;
    ss << compressed[compressTest];
    string temp;
    ss >> temp;

    EXPECT_EQ(temp, art.comp);


    compressTest++;
}

TEST_P(Mytest, decompTest)
{
    archivo = fopen(GetParam(), "r");
    art.fill(archivo);

    art.compress();
    art.decompress();

    stringstream ss;
    ss << decompressed[decompressTest];
    string temp;
    ss >> temp;

    bool equal = true;
    if(temp.length() == art.decomp.length())
    {
        for(int i = 0; i < temp.length(); i++)
        {
            if( temp[i] != art.decomp[i])
            {
                equal = false;
            }
        }
    }

    decompressTest++;
    ASSERT_TRUE(equal);
}


