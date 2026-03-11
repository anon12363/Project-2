def string_manipulator():
    print("=== Grok's String Manipulator ===")
    print("A simple string-based Python project!\n")
    
    while True:
        print("\nOptions:")
        print("1. Reverse string")
        print("2. Check palindrome")
        print("3. Count vowels")
        print("4. To uppercase")
        print("5. To lowercase")
        print("6. Length of string")
        print("7. Exit")
        
        choice = input("\nEnter your choice (1-7): ").strip()
        
        if choice == "7":
            print("Thanks for using Grok's String Manipulator! Goodbye.")
            break
        
        user_string = input("Enter a string: ")
        
        if choice == "1":
            print("Reversed:", user_string[::-1])
        elif choice == "2":
            cleaned = ''.join(user_string.lower().split())
            if cleaned == cleaned[::-1]:
                print("Yes, it's a palindrome!")
            else:
                print("No, it's not a palindrome.")
        elif choice == "3":
            vowels = "aeiouAEIOU"
            count = sum(1 for char in user_string if char in vowels)
            print(f"Number of vowels: {count}")
        elif choice == "4":
            print("Uppercase:", user_string.upper())
        elif choice == "5":
            print("Lowercase:", user_string.lower())
        elif choice == "6":
            print("Length:", len(user_string))
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    string_manipulator()
