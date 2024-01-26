import os
import pandas as pd
from azure.core.exceptions import ResourceNotFoundError
from azure.ai.formrecognizer import FormRecognizerClient, FormTrainingClient 
from azure.core.credentials import AzureKeyCredential
from azure.core.credentials import AzureKeyCredential
from azure.ai.formrecognizer import DocumentAnalysisClient


endpoint = "https://aguacate.cognitiveservices.azure.com/"
key = "c8c77eb6fcb041b2a79e5e88f10fb983"

model_id = "Agente_curriculums"
formUrl = "https://cdn-images.livecareer.es/images/lc/landings/examples/es/ejemplo-cv-informatico@3x.png"

document_analysis_client = DocumentAnalysisClient(
    endpoint=endpoint, credential=AzureKeyCredential(key)
)

# analizar el documento seleccionado
poller = document_analysis_client.begin_analyze_document_from_url(model_id, formUrl)
result = poller.result()

# extraer los campos analizados y escribirlos en archivo txt
for idx, document in enumerate(result.documents):
    print("--------Analizando documentos #{}--------".format(idx + 1))
    print("Tipo de documento: {}".format(document.doc_type))
    print("confidence: {}".format(document.confidence))
    print("Documento analizado por el modelo: {}".format(result.model_id))
    file=open("datos.txt","w")
    for name, field in document.fields.items():
        campos = field.value if field.value else field.content
        file.write(name+os.linesep+field.value+os.linesep+os.linesep)
        print("campo encontrado : {}".format(name))
    file.close()
    print("proceso finalizado")

        
