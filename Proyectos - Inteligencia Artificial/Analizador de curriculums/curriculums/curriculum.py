import nltk
from nltk.corpus import stopwords
from sklearn.feature_extraction.text import TfidfVectorizer

import PIL
from azure.cognitiveservices.vision.computervision import ComputerVisionClient
from azure.cognitiveservices.vision.computervision.models import OperationStatusCodes
from azure.cognitiveservices.vision.computervision.models import VisualFeatureTypes
from msrest.authentication import CognitiveServicesCredentials

import sys
import os
from array import array
from PIL import Image
import time


nltk.download('stopwords')

#obtnemos la llave y el endpoint de la api
subscription_key = "6ab80046f53749548278321172218e02"
endpoint = "https://cvreaderproject.cognitiveservices.azure.com/"

#accesamos a la API

computervision_client = ComputerVisionClient(endpoint, CognitiveServicesCredentials(subscription_key))

read_image_url = "https://cdn-images.livecareer.es/images/lc/landings/examples/es/ejemplo-cv-informatico@3x.png"
read_image_url = "https://www.micvideal.es/wp-content/uploads/sites/2/2022/09/ejemplo_de_curriculum_vitae_de_auxiliar_administrativo_con_plantilla_moderna.svg"
read_image_url = "https://cdn-images.zety.es/images/zety/landings/examples/ejemplos-de-curriculum-enfermera@3x.png"
read_image_url = "https://ejemplos-curriculum.com/wp-content/uploads/2021/03/budapest-spanish.png"
read_image_url = "https://cdn-images.zety.es/images/zety/landings/examples/ejemplos-de-curriculum-sin-experiencia@3x.png"
read_image_url = "https://cdn-images.livecareer.es/images/lc/landings/examples/es/ejemplo-cv-administracion@3x.png"
read_image_url = "https://cdn-images.zety.es/images/zety/landings/examples/es/ejemplos-de-curriculum-male-newcast.jpg"
read_image_url = "https://cdn-images.resumelab.com/images/rl/common/templates/es/cv-templates-resumelab-cubic@3x.png"
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
read_image_url = ""
#con el link de la imagen enviamos la solucitud a la api y pedimos que nos retorne le esta doel preceso

read_response = computervision_client.read(read_image_url,  raw=True)
read_operation_location = read_response.headers["Operation-Location"]
operation_id = read_operation_location.split("/")[-1]

#mientras el estado del proceso no sea completed se seguira ejecutando la api

while True:
    read_result = computervision_client.get_read_result(operation_id)

    if read_result.status not in ['notStarted', 'running']:
        break
    time.sleep(1)

# si ya se completo el proceso se guardara el curriculum en la variable cv

cv = ""

if read_result.status == OperationStatusCodes.succeeded:
    for text_result in read_result.analyze_result.read_results:
        for line in text_result.lines:
            cv += line.text
            cv += "\n"

# tokenize the extracted text
tokens = nltk.word_tokenize(cv)

# remove stop words
stop_words = set(stopwords.words('english'))
filtered_tokens = [token for token in tokens if not token.lower() in stop_words]

# vectorize the text
vectorizer = TfidfVectorizer()
vectorized_text = vectorizer.fit_transform(filtered_tokens)

print(vectorized_text)