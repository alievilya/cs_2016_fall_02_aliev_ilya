wget -q -O - http://rbc.ru| grep -o "http:.*" | grep -E -v "http://rbc.ru" > rbc.txt

