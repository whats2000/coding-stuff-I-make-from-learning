import requests as rq
from bs4 import BeautifulSoup

web_address = 'https://quotes.toscrape.com'
page = ''
author = []

while True:
    html = rq.get(web_address + page)

    print(f'Getting page {web_address}{page}')

    soup = BeautifulSoup(html.text, 'html.parser')
    
    # get author name of each cards
    for item in soup.select('small'):
        author.append(item.text)

    # check if we an turn to next page
    for item in soup.select('li > a'):
        page = item['href'] if 'Next' in item.text else ''

    if not page:
        break

# Output result
print('Result : ')
print('\n'.join(map(str, author)))
