def decrypt(encrypted_text, n):
    l = len(encrypted_text)
    enc = ""
    for _ in range(n):
        part1=encrypted_text[:l//2]
        part2=encrypted_text[l//2:]
        
        print(part1, part2)
                
        for i in range(len(part2)):
            enc += part2[i] 
            try:
                enc += part1[i]
            except:
                pass
            
        encrypted_text = enc
        enc = ""
        
    return encrypted_text


def encrypt(text, n):
    for _ in range(n):
        text = text[1::2] + text[::2]
        
    return text

print(encrypt("This is a test!", 1))
print(decrypt("hsi  etTi sats!", 1))