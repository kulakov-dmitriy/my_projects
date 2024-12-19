package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var rimNum = map[int]string{1: "I", 2: "II", 3: "III", 4: "IV", 5: "V", 6: "VI", 7: "VII", 8: "VIII", 9: "IX", 10: "X",
	20: "XX", 30: "XXX", 40: "XL", 50: "L", 60: "LX", 70: "LXX", 80: "LXXX", 90: "XC", 100: "C"}

func main() {
	for {
		readString, err := bufio.NewReader(os.Stdin).ReadString('\n')
		if err != nil {
			panic(err)
		}
		num, err := checkNum(readString)
		if err != nil {
			fmt.Println(err)
			return
		}
		fmt.Println(num)
	}
}
func checkNum(s string) (string, error) {
	split := strings.Split(s, " ")
	if len(split) != 3 {
		return "", errors.New("Вывод ошибки, так как формат математической операции не удовлетворяет заданию — два операнда и один оператор (+, -, /, *).")
	}
	sign := strings.TrimSpace(split[1])
	if sign != "-" && sign != "+" && sign != "/" && sign != "*" {
		return "", errors.New("Вывод ошибки, так как формат математической операции не удовлетворяет заданию — два операнда и один оператор (+, -, /, *).")
	}
	one, two := 0, 0
	for k, c := range rimNum {
		if strings.TrimSpace(split[0]) == c {
			one = k
		}
		if strings.TrimSpace(split[2]) == c {
			two = k
		}
	}
	if (one > 0 && one < 11) && (two > 0 && two < 11) {
		ress, err := NumRim(sign, one, two)
		if err != nil {
			return "", err
		}
		return ress, nil
	}
	atoiOne, err := strconv.Atoi(strings.TrimSpace(split[0]))
	atoiTwo, er := strconv.Atoi(strings.TrimSpace(split[2]))
	if err != nil && er != nil {
		return "", errors.New("Вывод ошибки, так как строка не является математической операцией.")
	}
	if err != nil || er != nil {
		return "", errors.New("Вывод ошибки, так как используются одновременно разные системы счисления.")
	}
	if (atoiOne < 1 || atoiOne > 10) || (atoiTwo < 1 || atoiTwo > 10) {
		return "", errors.New("Вывод ошибки, так как число больше 10 или меньше 1")
	}
	res, err := NumArab(sign, atoiOne, atoiTwo)
	if err != nil {
		return "", err
	}
	return strconv.Itoa(res), nil
}
func NumArab(sign string, one, two int) (res int, err error) {
	res, err = action(one, two, sign)
	if err != nil {
		return 0, err
	}
	return res, nil
}

func NumRim(sign string, one, two int) (res string, err error) {
	re, err := action(one, two, sign)
	if err != nil {
		return "", err
	}
	if re < 1 {
		return "", errors.New("Вывод ошибки, так как в римской системе нет отрицательных чисел.")
	}
	if re < 10 || re == 100 {
		return rimNum[re], nil
	}
	num1, num2 := re/10*10, re%10
	arabNum1, arabNum2 := "", ""
	for i, s := range rimNum {
		if num1 == i {
			arabNum1 = s
		}
		if num2 == i {
			arabNum2 = s
		}
	}
	res = arabNum1 + arabNum2
	return res, nil
}
func action(one int, two int, sign string) (res int, err error) {
	switch sign {
	case "-":
		res = one - two
	case "+":
		res = one + two
	case "/":
		res = one / two
	case "*":
		res = one * two
	default:
		return 0, errors.New("Не известный знак")
	}
	return res, nil
}
