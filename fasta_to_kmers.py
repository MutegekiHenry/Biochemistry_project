#!/home/rnabunje/.conda/envs/py3env/bin/python

import itertools
import time
import argparse
import sys 

parser = argparse.ArgumentParser(description='make kmers from .fasta read files')
parser.add_argument('-i', action="store", dest="input_file", help='input sequence.fa filename [required]', required=True)
parser.add_argument('-k', action="store", dest="kmer_size", type=int, default=21, help='kmer size [default=21]')
parser.add_argument('-o', action="store", dest="output_file", help='output filename [required]', required=True)
args = parser.parse_args()

seq_file=args.input_file
k=args.kmer_size
outfile=args.output_file

start1 = time.time()

def isheader(line):
    return line[0] == '>'
with open(seq_file) as f:
	for header,group in itertools.groupby(f, isheader):
		if not header:
			seq = "".join(line.strip() for line in group)
			#k = 21
			for i in range(0,len(seq)-k+1):
				kmer=''.join(seq[i:i+k])
				file = open(outfile, "a")
				file.write(kmer+'\n')
end1 =time.time()
elapsed1 =round(end1 - start1, 2)
elapsed1min =round(elapsed1/60, 2)
print (sys.argv[0], "runtime (minutes): ",elapsed1min)
