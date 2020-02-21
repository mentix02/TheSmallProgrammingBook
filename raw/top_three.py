from collections import defaultdict

def top_3_words(text):
    text = text.lower().strip(',').strip('.').strip('"')
    print(text)
    counter = defaultdict(int)
    for word in text.split():
        counter[word] += 1
    return sorted(
        counter.keys(),
        reverse=True,
        key = lambda item : counter[item]
    )

if __name__ == '__main__':
    print(top_3_words("a a a  b  c c  d d d d  e e e e e"))
