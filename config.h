#ifndef CONFIG_H
#define CONFIG_H

#define RED_COLOR "\x1b[31m"
#define GREEN_COLOR "\x1b[32m"
#define BLUE_COLOR "\x1b[34m"
#define YELLOW_COLOR "\x1b[33m"
#define CYAN_COLOR "\x1b[36m"
#define RESET_COLOR "\x1b[0m"

#define disable_line_break() printf("\033[?7l")
#define enable_line_break() printf("\033[?7h")

#endif // CONFIG_H