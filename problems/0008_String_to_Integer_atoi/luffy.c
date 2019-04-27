public int myAtoi(String str) {
        str = str.trim();// 去掉前导空白和尾部空白
        try {
            return Integer.parseInt(str);
        } catch (Exception e) {
            if (str.length() == 0)
                return 0;
            char c = str.charAt(0);
            if (c != '+' && c != '-' && (c - '0' < 0 || c - '0' > 9))
                return 0;
            else {
                StringBuffer sbuffer = new StringBuffer();
                sbuffer.append(str.charAt(0));
                for (int i = 1; i < str.length(); i++) {
                    char temp = str.charAt(i);
                    if (temp - '0' >= 0 && temp - '0' <= 9)
                        sbuffer.append(temp);
                    else
                        break;
                }
                if (sbuffer.length() == 1) {
                    if (sbuffer.charAt(0) == '+' || sbuffer.charAt(0) == '-')
                        return 0;
                    else
                        return Integer.parseInt(sbuffer.toString());
                } else {
                    if (sbuffer.charAt(0) == '+') {
                        str = sbuffer.substring(1, sbuffer.length());
                    } else {
                        str = sbuffer.toString();
                    }
                    try {
                        return Integer.parseInt(str);
                    } catch (Exception ee) {
                        if (str.charAt(0) == '-')
                            return Integer.MIN_VALUE;
                        else
                            return Integer.MAX_VALUE;
                    }
                }
            }
        }
    }

