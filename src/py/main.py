def restore_dinosaur_genome(fragments):

  nucleotides = set()
  for fragment in fragments:
    nucleotides.update(fragment)

  genome_index = {}
  for i, nucleotide in enumerate(nucleotides):
    genome_index[nucleotide] = i

  fragments.sort(key=len)

  genome = ""

  for fragment in fragments[::-1]
    start_index = genome.find(fragment[0])

    if start_index == -1:
      genome = genome[:start_index] + fragment + genome[start_index:]

    else:
      end_index = genome_index[fragment[-1]]
      
      if end_index >= start_index:
        genome = genome[:start_index] + genome[end_index + 1:]

  return genome


fragments = []
n = int(input())
for i in range(n):
  fragments.append(input())

genome = restore_dinosaur_genome(fragments)

print(genome)
