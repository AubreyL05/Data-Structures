# Project Outline - Luke Aubrey - Hospital Patient Dataset

## Motivation
I chose the Hospital Patient Dataset because I have a strong interest in data-driven healthcare management. The dataset, which includes variables like length of stay and cost, offers a practical opportunity to analyze the efficiency of healthcare operations. Sorting the data by length_of_stay in descending order allows me to immediately identify the cases that required the longest hospitalizations.

## Data Description
### Dataset Source
* https://www.kaggle.com/datasets/blueblushed/hospital-dataset-for-practice?resource=download/

### Selected Variables of Interest
* `PatientID` - Unique identifer of each patient
* `Age` - Patient's age
* `Procedure` - The medical procedure performed on patient
* `Cost` - Cost of the procedure
* `Length_of_Stay` - How many days patient spent in the hospital.

### Data Preperation
1. Downloaded the CSV file of an example hospital dataset from Kaggle.
2. Removed unnecessary variables, no need to remove rows as dataset = maximum of 1000 patients.
3. Selected `Length_of_Stay` as the key for sorting my ASList in descending order. So, patients that have spent the most time in the hospital will appear first.
4. Verified that all values are valid for parsing for C++.