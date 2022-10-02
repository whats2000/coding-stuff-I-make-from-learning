import requests as rq
from bs4 import BeautifulSoup

web_address = 'https://quotes.toscrape.com'
page = ''
count_tag = {}

while True:
    html = rq.get(web_address + page)

    print(f'Getting page {web_address}{page}')

    soup = BeautifulSoup(html.text, 'html.parser')

    # calculate counts of the tags
    for item in soup.select('a.tag'):
        if item.text in count_tag.keys():
            count_tag[item.text] += 1
        else:
            count_tag[item.text] = 1

    # check if we an turn to next page
    for item in soup.select('li > a'):
        page = item['href'] if 'Next' in item.text else ''

    if not page:
        break

# Output result
print('Result : ')

for key in count_tag.keys():
    print(f'{key} : {count_tag[key]}')
