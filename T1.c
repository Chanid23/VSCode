#include <stdio.h>

// ��������
int isLeapYear(int year);  // �ж��Ƿ�������
int getWeekday(int year, int month, int day);  // ��ȡĳ�������ڼ�
void printMonthCalendar(int year, int month);  // ��ӡĳ�µ�������
void printYearCalendar(int year);  // ��ӡĳ���������

// ������
int main()
{
    int choice, year, month;

    printf("��ѡ��˵���\n");
    printf("1. �������£�������µ�������\n");
    printf("2. ������ݣ���������������\n");
    printf("��ѡ�������Ӧ���֣���");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("��������ݣ�");
        scanf("%d", &year);

        if (year < 1900)
        {
            printf("������1900���Ժ����ݣ�\n");
            return 0;
        }

        printf("�������·ݣ�");
        scanf("%d", &month);

        if (month < 1 || month > 12)
        {
            printf("������Ϸ����·ݣ�\n");
            return 0;
        }

        if (month == 2 && isLeapYear(year))
        {
            printf("%d��\n%d��\nMON TUE WED THU FRI SAT SUN\n", year, month);
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
        printf("��������ݣ�");
        scanf("%d", &year);

        if (year < 1900)
        {
            printf("������1900���Ժ����ݣ�\n");
            return 0;
        }

        printYearCalendar(year);
        break;

    default:
        printf("��ѡ����ȷ�Ĳ˵�ѡ�\n");
        break;
    }

    return 0;
}

// �ж��Ƿ�������
int isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

// ��ȡĳ�������ڼ�
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

// ��ӡĳ�µ�������
void printMonthCalendar(int year, int month)
{
    int days;  // ���µ�������
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
            printf("������Ϸ����·ݣ�\n");
            return;
    }

    int weekday = getWeekday(year, month, 1);  // ����1�������ڼ�

    printf("%d��\n%d��\nMON TUE WED THU FRI SAT SUN\n", year, month);

    // ��ӡǰ��Ŀո�
    for (int i = 0; i < weekday; i++)
    {
        printf("   ");
    }

    // ��ӡ����
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


// ��ӡĳ���������
void printYearCalendar(int year)
{
    printf("%d��\n", year);
    for (int month = 1; month <= 12; month++)
    {
        printMonthCalendar(year, month);
    }
}
    