import re

def check_password_strength(password):
    """
    Checks the strength of a password based on common criteria.
    
    Criteria:
    - Length: At least 8 characters
    - Uppercase: At least one uppercase letter
    - Lowercase: At least one lowercase letter
    - Number: At least one digit
    - Special: At least one special character
    
    Returns a dictionary with strength score (0-5) and feedback.
    """
    strength = 0
    feedback = []
    
    # Length check
    if len(password) >= 8:
        strength += 1
    else:
        feedback.append("Password should be at least 8 characters long.")
    
    # Uppercase check
    if re.search(r'[A-Z]', password):
        strength += 1
    else:
        feedback.append("Include at least one uppercase letter.")
    
    # Lowercase check
    if re.search(r'[a-z]', password):
        strength += 1
    else:
        feedback.append("Include at least one lowercase letter.")
    
    # Digit check
    if re.search(r'\d', password):
        strength += 1
    else:
        feedback.append("Include at least one number.")
    
    # Special character check
    if re.search(r'[!@#$%^&*(),.?":{}|<>]', password):
        strength += 1
    else:
        feedback.append("Include at least one special character (e.g., !@#$%).")
    
    # Determine strength level
    if strength >= 4:
        level = "Strong"
    elif strength >= 3:
        level = "Medium"
    else:
        level = "Weak"
    
    return {
        'strength_score': strength,
        'level': level,
        'feedback': feedback
    }

# Example usage
if __name__ == "__main__":
    password = input("Enter a password to check: ")
    result = check_password_strength(password)
    print(f"Strength Score: {result['strength_score']}/5")
    print(f"Level: {result['level']}")
    print("Feedback:")
    for item in result['feedback']:
        print(f"- {item}")
