import datetime
from hashlib import sha256


class Blok:
    def __init__(self, previous_block_hash, data, timestamp):
        self.previous_block_hash = previous_block_hash
        self.data = data
        self.timestamp = timestamp
        self.hash = self.get_hash

    @staticmethod
    def create_genesis_block():
        return Blok("0", "0", datetime.datetime.now())

    @property
    def get_hash(self):
        header_bin = (str(self.previous_block_hash) +
                      str(self.data) +
                      str(self.timestamp))

        inner_hash = sha256(header_bin.encode()).hexdigest().encode()
        outer_hash = sha256(inner_hash).hexdigest()

        return outer_hash


num_blocks_to_add = 5

block_chain = [Blok.create_genesis_block()]

print("Genesis Blok'u.")
print("Hash: %s" % block_chain[0].hash)

for i in range(1, num_blocks_to_add):
    block_chain.append(Blok(block_chain[i - 1].hash,
                            "Block number %d" % i,
                            datetime.datetime.now()))
    print("\nBlok #%d olusturuldu." % i)
    print("Hash: %s" % block_chain[-1].hash)
    print("Pre Hash: %s" % block_chain[-2].hash)
    print("timestamp: %s" % datetime.datetime.now())
