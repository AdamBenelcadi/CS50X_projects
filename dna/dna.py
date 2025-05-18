import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3 or not sys.argv[2].endswith('.txt') or not sys.argv[1].endswith('.csv'):
        print("Unsupported Format !")
        return

    # Read database file into a variable
    with open(sys.argv[1], 'r') as file:
        database = csv.DictReader(file)
        rows = list(database)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        person = file.read()

    # Find longest match of each STR in DNA sequence
    AGATC = longest_match(person, "AGATC")
    AATG = longest_match(person, "AATG")
    TATC = longest_match(person, "TATC")
    TTTTTTCT = longest_match(person, "TTTTTTCT")
    TCTAG = longest_match(person, "TCTAG")
    GATA = longest_match(person, "GATA")
    GAAA = longest_match(person, "GAAA")
    TCTG = longest_match(person, "TCTG")
    # Check database for matching profiles
    if sys.argv[1] == "databases/small.csv":
        for row in rows:
            if int(row['AGATC']) == AGATC and int(row['AATG']) == AATG and int(row['TATC']) == TATC:
                print(row['name'])
                return
        else:
            print("No match")
    if sys.argv[1] == "databases/large.csv":
        for row in rows:
            if int(row['AGATC']) == AGATC and int(row['AATG']) == AATG and int(row['TATC']) == TATC and int(row['TTTTTTCT']) == TTTTTTCT and int(row['TCTAG']) == TCTAG and int(row['GATA']) == GATA and int(row['GAAA']) == GAAA and int(row['TCTG']) == TCTG:
                print(row['name'])
        else:
            print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run


main()
