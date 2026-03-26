import pandas as pd
import matplotlib.pyplot as plt

courses = [95.15, 2.7, 1.75, 0.15,0.06, 0.03,0.16]
labels = ['CO_2','N_2','Ar','O_2','CO','H_20','Other']
dictionary = {'courses':courses, 'labels':labels}
python_pie_chart_df = pd.DataFrame(dictionary)

#plt.pie(x = python_pie_chart_df.courses, labels = python_pie_chart_df.labels)
#plt.show()

plt.pie(x = python_pie_chart_df.courses,autopct='%1.1f%%')
plt.legend(labels = python_pie_chart_df.labels, loc = [0.95,0.35])
plt.show()

#plt.pie(x = python_pie_chart_df.courses, labels = python_pie_chart_df.labels, #autopct='%1.1f%%')
#plt.show()

##Gas %
#CO_2 95.15
#N_2 2.7%
#Ar 1.75
#O_2  0.15
#CO 0.06
#H_2O 0.03
#Other 0.16
