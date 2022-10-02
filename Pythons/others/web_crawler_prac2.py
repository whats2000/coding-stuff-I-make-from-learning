import requests as rq
from bs4 import BeautifulSoup

web_address = 'https://www.ptt.cc/bbs/Stock'  # request address
target = '台積電'  # the word we are finding
time = 20  # check how many page

page = ''
count = 0

for i in range(20):
    html = rq.get(web_address + page)

    print(f'Getting page {web_address}{page}')

    soup = BeautifulSoup(html.text, 'html.parser')

    # calculate counts of the target
    for item in soup.select('div.title > a'):
        print(item.text)
        if target in item.text:
            count += 1

    # check if we an turn to next page
    for item in soup.select('div.btn-group-paging > a'):
        if '‹ 上頁' in item.text:
            page = item['href']
            page = page.replace('/bbs/Stock', '')

    if not page:
        break

# Output result
print('Result : ')
print(f'{target} is appear {count} times')
