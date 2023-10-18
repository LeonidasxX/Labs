!pip install --upgrade scikit-learn
!pip install scipy
!pip3 install -U scikit-learn scipy matplotlib

For DecisionBoundary Display

!pip3 uninstall matplotlib.pyplot --yes

!pip3 install matplotlib.pyplot

SOLVED EXAMPLE

# Load the important packages
from sklearn.datasets import load_breast_cancer
import matplotlib.pyplot as plt
from sklearn.inspection import DecisionBoundaryDisplay
from sklearn.svm import SVC
# Load the datasets
cancer = load_breast_cancer()
X = cancer.data[:, :2]
y = cancer.target
#Build the model
svm = SVC(kernel="rbf", gamma=0.5, C=1.0)
# Trained the model
svm.fit(X, y)
# Plot Decision Boundary
DecisionBoundaryDisplay.from_estimator(svm,X,response_method="predict",cmap=plt.cm.Spectral,alpha=0.8,xlabel=cancer.feature_names[0],ylabel=cancer.feature_names[1],)
# Scatter plot
plt.scatter(X[:, 0], X[:, 1],c=y,s=20, edgecolors="k")
plt.show()

######################################################################################################

QUESTION
Using Radial Basis Function

# Load the important packages
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt
from sklearn.inspection import DecisionBoundaryDisplay
from sklearn.svm import SVC
# Load the datasets
iris = load_iris()
X = iris.data[:, :2]
y = iris.target
#Build the model
svm = SVC(kernel="rbf", gamma=0.5, C=1.0)
# Trained the model
svm.fit(X, y)
# Plot Decision Boundary
DecisionBoundaryDisplay.from_estimator(svm,X,response_method="predict",cmap=plt.cm.Spectral,alpha=0.8,xlabel=iris.feature_names[0],ylabel=iris.feature_names[1],)
# Scatter plot
plt.scatter(X[:, 0], X[:, 1],c=y,s=20, edgecolors="k")
plt.show()

################################################################################################
Using Sigmoid Function

# Load the important packages
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt
from sklearn.inspection import DecisionBoundaryDisplay
from sklearn.svm import SVC
# Load the datasets
iris = load_iris()
X = iris.data[:, :2]
y = iris.target
#Build the model
svm = SVC(kernel="sigmoid", gamma=0.5, C=1.0)
# Trained the model
svm.fit(X, y)
# Plot Decision Boundary
DecisionBoundaryDisplay.from_estimator(svm,X,response_method="predict",cmap=plt.cm.Spectral,alpha=0.8,xlabel=iris.feature_names[0],ylabel=iris.feature_names[1],)
# Scatter plot
plt.scatter(X[:, 0], X[:, 1],
c=y,
s=20, edgecolors="k")
plt.show()

#################################################################################################################

Using Linear Function

# Load the important packages
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt
from sklearn.inspection import DecisionBoundaryDisplay
from sklearn.svm import SVC
# Load the datasets
iris = load_iris()
X = iris.data[:, :2]
y = iris.target
#Build the model
svm = SVC(kernel="linear", gamma=0.5, C=1.0)
# Trained the model
svm.fit(X, y)
# Plot Decision Boundary
DecisionBoundaryDisplay.from_estimator(svm,X,response_method="predict",cmap=plt.cm.Spectral,alpha=0.8,xlabel=iris.feature_names[0],ylabel=iris.feature_names[1],)
# Scatter plot
plt.scatter(X[:, 0], X[:, 1],
c=y,
s=20, edgecolors="k")
plt.show()
