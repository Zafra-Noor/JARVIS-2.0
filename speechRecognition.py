import pyttsx3
import speech_recognition as sr

# an use google cloud.
# speech engine initialization.

engine=pyttsx3.init()
voices = engine.setProperty('rate', 180)
engine.setProperty('volume', 1.0)

# define a function to speak a given text:
def speak(audio):
	engine.say(audio)	    # text will be passed to the engine.
	engine.runAndWait() 	# engine will run and wait for output 

def takeCommand():
	r=sr.Recognizer()	    # recognizer
	query = " "
	with sr.Microphone() as source:
			print("listnening ......")
			r.pause_threshold = 1
			audio = r.listen(source)
			print(audio)	    # listen to the source
	try:
			print("Recognizing ......")
			query = r.recognize_google(audio, language='en-in')	#recognize the audio
			print(f"User said: {query}\n")	                    #print
			
	except: 
			print ("sorry can't understand your saying")        #Print a message if the speech is not recognized.
	return query                                        #return an empty set.

if __name__ == "__main__":
    text = takeCommand()
    with open("recognized_text.txt", "w") as file:
        file.write(text)