#include <pwch/gui/wxHeaders.h>

#define PWCH_resolutionX wxSystemSettings::GetMetric(wxSYS_SCREEN_X)
#define PWCH_resolutionY wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)
#define PWCH_mainWidth 550
#define PWCH_mainHeight 400
#define PWCH_centerX (PWCH_resolutionX / 2) - (PWCH_mainWidth / 2)
#define PWCH_centerY (PWCH_resolutionY / 2) - (PWCH_mainHeight / 2)