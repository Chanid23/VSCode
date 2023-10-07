#include <stdio.h>

// 函数声明
int isLeapYear(int year);  // 判断是否是闰年
int getWeekday(int year, int month, int day);  // 获取某天是星期几
void printMonthCalendar(int year, int month);  // 打印某月的万年历
void printYearCalendar(int year);  // 打印某年的万年历

// 主函数
int main()
{
    int choice, year, month;

    printf("请选择菜单：\n");
    printf("1. 输入年月，输出该月的万年历\n");
    printf("2. 输入年份，输出该年的万年历\n");
    printf("请选择（输入对应数字）：");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("请输入年份：");
        scanf("%d", &year);

        if (year < 1900)
        {
            printf("请输入1900年以后的年份！\n");
            return 0;
        }

        printf("请输入月份：");
        scanf("%d", &month);

        if (month < 1 || month > 12)
        {
            printf("请输入合法的月份！\n");
            return 0;
        }

        if (month == 2 && isLeapYear(year))
        {
            printf("%d年\n%d月\nMON TUE WED THU FRI SAT SUN\n", year, month);
            printf("              01  02  03  04  05  06  07\n");
            printf("08  09  10  11  12  13  14\n");
            printf("15  16  17  18  19  20  21\n");
            printf("22  23  24  25  26  27  28\n");
        }
        else
        {
            printMonthCalendar(year, month);
        }
        break;

    case 2:
        printf("请输入年份：");
        scanf("%d", &year);

        if (year < 1900)
        {
            printf("请输入1900年以后的年份！\n");
            return 0;
        }

        printYearCalendar(year);
        break;

    default:
        printf("请选择正确的菜单选项！\n");
        break;
    }

    return 0;
}

// 判断是否是闰年
int isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

// 获取某天是星期几
int getWeekday(int year, int month, int day)
{
    if (month < 3)
    {
        month += 12;
        year--;
    }
    int c = year / 100;
    year %= 100;
    int week = (c / 4) - 2 * c + (year / 4) + (13 * (month + 1) / 5) + day - 1;
    while (week < 0)
        week += 7;
    return week % 7;
}

// 打印某月的万年历
void printMonthCalendar(int year, int month)
{
    int days;  // 当月的总天数
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            days = (isLeapYear(year)) ? 29 : 28;
            break;
        default:
            printf("请输入合法的月份！\n");
            return;
    }

    int weekday = getWeekday(year, month, 1);  // 当月1号是星期几

    printf("%d年\n%d月\nMON TUE WED THU FRI SAT SUN\n", year, month);

    // 打印前面的空格
    for (int i = 0; i < weekday; i++)
    {
        printf("   ");
    }

    // 打印日期
    for (int day = 1; day <= days; day++)
    {
        printf("%02d ", day);
        if ((weekday + day) % 7 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}


// 打印某年的万年历
void printYearCalendar(int year)
{
    printf("%d年\n", year);
    for (int month = 1; month <= 12; month++)
    {
        printMonthCalendar(year, month);
    }
}
    