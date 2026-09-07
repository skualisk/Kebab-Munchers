/*Supermarket management system, by Aarron Dcruz 2661123, Anshuman Singh 2661126, 
  Yankit Gupta 2661144 and Uneeth Singh 2661183*/
#import <stdio.h>
#import <string.h>
struct Cart //Bro struct is like a reusable variable thing
{
  char pname[50];
  float price;
  float quan;
  
}
struct Product{
    int ASid;
    char ASname[50];
    float ASprice;
    int ASquantity;
}
void AddCart();

void RemoveCart();

void ASaddProduct();
int main()
{

}

void AddCart()
{
  struct Cart Ad;
  printf("Enter Product Name: ");
  gets(Ad.pname);
  printf("Enter Price of Product");  // Am thinking we read this from our inventory.csv file but little complex
  scanf("%f", &Ad.price);
  printf("Enter Quantity of Product");
  scanf("%f", &Ad.quan)

  FILE *fad = fopen("Cart.csv", "a");
  if (fad == NULL)
  {
    printf("File not Found");
    exit(0);
  }
  fprintf(fad, %s, %.4f, %.2f, Ad.pname, Ad.price, Ad.quan);   // Another thinng, do we add tax per item or tax the whole thing
  printf("-------------- ITEM ADDED SUCCESSFULLY --------------");

  f.close(fad);
}

void RemoveCart()
{
  char IName[50];
  printf("Enter Item Name to be removed:\t");
  gets(IName);
  File *fde = fopen("Cart.csv", r);
  File *ftemp = fopen("Temp.csv", a);
  char line[256];
  int found;
  while (fgets(line, sizeof[line], fde) != NULL)
  {
    line(strcspn(line, "\n")) = 0;
    char *name = strok(line, ",");
    char *price = strok(NULL, ",");
    char *quan = strok(NULL, ",");
    if (strcmp(IName, *name) == 0)
    {
      found = 1;
      continue;
    }
    fprintf(ftemp, %s, %s, %s, *name, *price, *quan);
  }
  fclose(fde);
  fclose(ftemp);
  if (found == 1)
  {
    printf("Item Not Found");
  }
  else
    printf("----------------- ITEM DELETED FROM CART -----------------");
  remove ("Cart.csv");
  rename ("Temp.csv", "Cart.csv");
}
void ASaddProduct(){
	struct Product ASproduct;
	FILE*ASfile;
	
	ASfile=fopen("products.txt",a);//opening file in apppppeeeennnddd
	if(ASfile==NULL){
		printf("ERROR!!\n");
		return;
	}
	//taking product
	printf("ENTER PRODUCT ID:");
	scanf("%d",&ASproduct.ASid);
	printf("ENTER PRODUCT NAME:");
	scanf("%d",&ASproduct.ASname);
	printf("ENTER PRODUCT PRICE:");
	scanf("%d",&ASproduct.ASprice);
	printf("ENTER PRODUCT QUANTITY:");
	scanf("%d",&ASproduct.ASquantity);
	fprintf(ASfile,"%d %s %.2f %d\n",ASproduct.ASid,ASproduct.ASname,ASproduct.ASprice,ASproduct.ASquantity);
	
	fclose(ASfile);
	printf("\n PRODUCT ADDED !\n");
	
}   
void ASdisplayProducts() {
    struct Product ASproduct;
    FILE *ASfile;

    // Open file in read mode
    ASfile = fopen("products.txt", "r");
    if (ASfile == NULL) {
        printf(" Error!\n");
        return;
    }

    printf("\n--- Product List ---\n");
    printf("ID\tName\tPrice\tQuantity\n");
    printf("---------------------------------\n");

    // Read each product line by line
    while (fscanf(ASfile, "%d %s %f %d",
                  &ASproduct.ASid,
                  ASproduct.ASname,
                  &ASproduct.ASprice,
                  &ASproduct.ASquantity) != EOF) {
        printf("%d\t%s\t%.2f\t%d\n",
               ASproduct.ASid,
               ASproduct.ASname,
               ASproduct.ASprice,
               ASproduct.ASquantity);
    }

    fclose(ASfile);
}
